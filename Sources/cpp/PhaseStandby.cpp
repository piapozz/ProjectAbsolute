#include "../header/PhaseStandby.h"
#include "../header/UIOfficer.h"
#include "../header/ObjectFactory.h"
#include "../header/UIOfficerList.h"
#include "../header/InputManager.h"
#include "../header/Camera.h"

void PhaseStandby::Init()
{
	// 入力受付クラスを生成
	// // 入力の初期化
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
	 UIScreenText* uiMoney = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(Transform(MONEY_POS, MONEY_SIZE), LayerSetting{true, false, Layer::MIDDLE});
	 uiMoney->SetText("所持金: 1000G");
	// 区画に生成するキャラクターUI
	trans = Transform(DIVISION_POS, DIVISION_SIZE);
	layer = {true, false, Layer::BACK};
	UIOfficerList* uiDIVISIONList = ObjectFactory::Instance().CreateWithArgs<UIOfficerList>(trans, layer);
	// 控えキャラクターUI
	trans = Transform(OFFICERLIST_POS, OFFICERLIST_SIZE);
	layer = {true, false, Layer::BACK};
	UIOfficerList* uiOfficerList = ObjectFactory::Instance().CreateWithArgs<UIOfficerList>(trans, layer);
	// 開始ボタン
	trans = Transform(START_POS, START_SIZE);
	layer = {true, true, Layer::BACK};
	UIScreenButton* startButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	startButton->SetText("Start");
	startButton->SetCallback([this]() {
		this->ChangePhase(PhaseName::MAIN);
	});
	// 雇用ボタン
	trans = Transform(HIRE_POS, HIRE_SIZE);
	layer = {true, true, Layer::BACK};
	UIScreenButton* hireButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	hireButton->SetText("雇用");
	hireButton->SetCallback([this]() {
		this->ChangePhase(PhaseName::MAIN);
	});

	// カメラ生成
	_pCamera = new Camera();
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

}

void PhaseStandby::RPushInputProc(Vector2 pos)
{

}

void PhaseStandby::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	
}

void PhaseStandby::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	
}

void PhaseStandby::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// ワールド座標に変更
	Camera* camera = Camera::instance;

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