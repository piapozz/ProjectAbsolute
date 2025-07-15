#include "../header/PhaseStandby.h"
#include "../header/UIOfficer.h"
#include "../header/ObjectFactory.h"
#include "../header/UIOfficerList.h"
#include "../header/InputManager.h"
#include "../header/Camera.h"
#include "../header/UIOfficerIcon.h"
#include "../header/Officermanager.h"
#include "../header/DataManager.h"

void PhaseStandby::Init()
{
	// 入力受付クラスを生成
	// 入力の初期化
	InputManager& inputManager = InputManager::Instance();
	inputManager.SetOnCursorCallback([this](Vector2 pos){ this->OnCursorProc(pos); });
	inputManager.SetLPushCallback([this](Vector2 pos){ this->LPushInputProc(pos); });
	inputManager.SetLDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->LDrackInputProc(pos, oldPos); });
	inputManager.SetLReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->LReleaseInputProc(pos, oldPos); });
	inputManager.SetRPushCallback([this](Vector2 pos){ this->RPushInputProc(pos); });
	inputManager.SetRDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->RDrackInputProc(pos, oldPos); });
	inputManager.SetRReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->RReleaseInputProc(pos, oldPos); });
	inputManager.SetWheelRotCallback([this](Vector2 pos, int rot){ this->WheelRotInputProc(pos, rot); });
	inputManager.SetEscapeCallback([this](){ this->EscapeInputProc(); });

	// キャラの詳細UI(入力なし)
	Transform trans = Transform(OFFICCER_UI_POS, OFFICCER_UI_SIZE);
	LayerSetting layer = {false , false , Layer::MIDDLE};
	UIOfficer* uiOfficer = ObjectFactory::Instance().CreateWithArgs<UIOfficer>(trans, true, layer);
	// 所持金UI(入力なし)
	_money = DataManager::Instance().GetMoney();
	uiMoney = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(Transform(MONEY_POS, MONEY_SIZE), LayerSetting{true, false, Layer::MIDDLE});
	uiMoney->SetText(std::to_string(_money) + "GG");
	// 区画に生成するキャラクターUI
	trans = Transform(DIVISION_POS, DIVISION_SIZE);
	layer = {true, true, Layer::BACK};
	uiDivisuinList = ObjectFactory::Instance().CreateWithArgs<UIOfficerList>(trans, layer);
	// 控えキャラクターUI
	trans = Transform(OFFICERLIST_POS, OFFICERLIST_SIZE);
	layer = {true, true, Layer::BACK};
	uiOfficerList = ObjectFactory::Instance().CreateWithArgs<UIOfficerList>(trans, layer);
	// 開始ボタン
	trans = Transform(START_POS, START_SIZE);
	layer = {true, true, Layer::BACK};
	UIScreenButton* startButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	startButton->SetText("Start");
	startButton->SetCallback([this]() {

		std::vector<BaseOfficer*> officers = uiDivisuinList->GetOfficerList();
		std::vector<OfficerInitData> datas;
		for (BaseOfficer* officer : officers){
			datas.push_back(officer->GetOfficerInitData());
		}
		DataManager::Instance().SetOfficerData(datas);

		this->ChangePhase(PhaseName::MAIN);
	});
	// 雇用ボタン
	trans = Transform(HIRE_POS, HIRE_SIZE);
	layer = {true, true, Layer::BACK};
	UIScreenButton* hireButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	std::string hireText = "雇用(" + std::to_string(HIRE_COST) + "GG" + ")";
	hireButton->SetText(hireText);
	hireButton->SetCallback([this]() 
	{
		// 所持金が足りない場合は何もしない
		if (_money < HIRE_COST) return; 
		_money -= HIRE_COST;
		DataManager::Instance().SetMoney(_money);
		// 雇用ボタンのテキスト更新
		this->uiMoney->SetText(std::to_string(_money) + "GG");
		OfficerInitData data;
		BaseOfficer* newOfficer = OfficerManager::Instance().AddOfficer(OfficerType::PLAYER, data, Vector2(0, 0));
		this->uiOfficerList->AddOfficer(newOfficer);
	});

	// カメラ生成
	_pCamera = new Camera();

	// アイコンのコールバック設定
	UIOfficerIcon::startDrackCallback = [](UIOfficerIcon* icon) {
		// 親のリストから削除
		UIOfficerList* parent = icon->GetOfficerList();
		if (parent != nullptr) {
			parent->RemoveOfficer(icon->GetOfficer());
			// 親を解除
			icon->SetParent(nullptr);
			// オブジェクトのスケールをローカルに設定
			icon->SetSize(Vector2(WINDOW_WIDTH * (1.0f / 20.0f), WINDOW_HEIGHT * (2.0f / 20.0f)));
		}
	};

	UIOfficerIcon::onDrackCallback = [](UIOfficerIcon* icon) {
		// マウスに追従処理
		Vector2 mousePos = InputManager::Instance().GetCursorScreenPos();
		icon->SetPosition(mousePos - (icon->GetScale() * 0.5f));
	};

	UIOfficerIcon::endDrackCallback = [](UIOfficerIcon* icon) {
		// ドロップ位置に応じて処理
		Vector2 dropPos = icon->GetTransform().GetWorldTransform().position;

		// ドロップ先のオブジェクト群を取得
		std::vector<BaseObject*> dropObjects = ObjectManager::Instance().FindPosAllObject(dropPos, ObjectType::SCREEN_UI);

		// UIOfficerList を見つけたかどうか
		bool added = false;

		for (BaseObject* obj : dropObjects) {
			UIOfficerList* officerList = dynamic_cast<UIOfficerList*>(obj);
			if (officerList != nullptr) {
				officerList->AddOfficer(icon);
				added = true;
				break; 
			}
		}

		if (!added) {
			// 見つからなかったので元のリストに戻す
			UIOfficerList* originalList = icon->GetOfficerList();
			if (originalList != nullptr) {
				originalList->AddOfficer(icon);
			}
		}
	};

	// ここでオフィサーを生成する
	std::vector<OfficerInitData> datas = DataManager::Instance().GetOfficerData();
	for(const OfficerInitData& data : datas)
	{
		BaseOfficer* officer = OfficerManager::Instance().AddOfficer(data.type, data, Vector2::zero());
		uiDivisuinList->AddOfficer(officer);
	}
}

void PhaseStandby::OnCursorProc(Vector2 pos)
{
	// 以前乗っていたオブジェクトを乗っていなくする
	BaseObject* onCursorObj = InputManager::Instance().GetOnCursorObject();
	if (onCursorObj != nullptr)
	{
		onCursorObj->NotOnCursor();
	}

	// スクリーンUI
	// UIの取得
	BaseObject* screenUI = ObjectManager::Instance().FindPosObject(pos);
	if (screenUI != nullptr)
	{
		screenUI->OnCursor();
		InputManager::Instance().SetOnCursorObject(screenUI);
		return;
	}

}

void PhaseStandby::LPushInputProc(Vector2 pos)
{
	// ワールド座標に変更
	Camera* camera = Camera::instance;

	// スクリーンUI
	BaseObject* object = ObjectManager::Instance().FindPosObject(pos);
	if (object != nullptr)
	{
		object->StartDrack();
		drackingObjects.push_back(object);
		return;
	}

}

void PhaseStandby::RPushInputProc(Vector2 pos)
{

}

void PhaseStandby::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	for (BaseObject* object: drackingObjects)
	{
		object->OnDrack();
	}
}

void PhaseStandby::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
}

void PhaseStandby::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// ワールド座標に変更
	Camera* camera = Camera::instance;

	for (BaseObject* object: drackingObjects)
	{
		object->EndDrack();
	}
	drackingObjects.clear();

	// クリックが離されたなら
	if (InputManager::Instance().IsLeftClick(pos))
	{
		// スクリーンUI
		BaseObject* object = ObjectManager::Instance().FindPosObject(pos);
		if (object != nullptr)
		{
			object->ClickEvent();
			return;
		}
	}
}

void PhaseStandby::RReleaseInputProc(Vector2 pos, Vector2 oldPos)
{

}

void PhaseStandby::WheelRotInputProc(Vector2 pos, int rot)
{

}

void PhaseStandby::EscapeInputProc()
{

}