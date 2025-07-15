#include "../header/PhaseMain.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/Camera.h"
#include "../header/InputManager.h"
#include "../header/Entity_E000.h"
#include "../header/EventManager.h"
#include "../header/UIScreenButton.h"
#include "../header/SelectOperationUI.h"
#include "../header/BaseOfficer.h"
#include "../header/SecureRoom.h"
#include "../header/ObjectFactory.h"
#include "../header/CommonModule.h"
#include "../header/EntityManager.h"
#include "../header/UIEntity.h"
#include "../header/UIOfficer.h"
#include "../header/DataManager.h"
#include "../header/ContinueResultUI.h"

std::vector<OfficerPlayer*>& PhaseMain::GetSelectOfficerList(){ return _pSelectOfficerList; }
std::vector<OfficerPlayer*> PhaseMain::_pSelectOfficerList;

void PhaseMain::Init()
{
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

	StageManager::Instance().Init();
	StageManager::Instance().SetStageData(_stageData[GetDay()]);
	StageManager::Instance().CreateStage();
	OfficerManager::Instance().Init();
	LayerSetting layerSetting = {true, true, Layer::MIDDLE};
	// エンティティの生成
	vector<BaseEntity*> addEntity = EntityManager::Instance().AddObjectEntity();
	for (int i = 0, max = addEntity.size(); i < max; i++)
	{
		int roomID = addEntity[i]->GetManagementData().roomID;
		StageManager::Instance().SetEntity(addEntity[i], roomID);
	}
	EventManager::Instance().Init();
	SecureRoom::EndOperationEvent = [this](int successCount)
	{
		// 作業が終了したら、エネルギーを追加
		EventManager::Instance().AddEnergy(successCount);
		if (EventManager::Instance().IsMaxEnergy())
			_pResultUI->SetActive(true);
	};
	// UI
	ObjectFactory& factory = ObjectFactory::Instance();
	layerSetting = {true, false, Layer::FRONT};
	_pRangeSelect = factory.CreateWithArgs<UIScreenButton>(Transform(), false, layerSetting);
	_pSelectOperationUI = factory.CreateWithArgs<SelectOperationUI>();
	SecureRoom::GetUIOperationCallback = [this]()
	{
		return _pSelectOperationUI;
	};
	_pEntityUI = factory.CreateWithArgs<UIEntity>();
	SecureRoom::GetUIEntityCallback = [this]()
	{
		return _pEntityUI;
	};
	layerSetting = {false, false, Layer::MIDDLE};
	Transform trans = Transform(Vector2(WINDOW_WIDTH - (WINDOW_WIDTH / 10), WINDOW_HEIGHT / 5), Vector2(WINDOW_WIDTH / 5, WINDOW_HEIGHT / 2.5f));
	_pOfficerUI = factory.CreateWithArgs<UIOfficer>(trans, true, layerSetting);
	OfficerPlayer::GetUIOfficerCallback = [this]()
	{
		return _pOfficerUI;
	};
	_pResultUI = factory.CreateWithArgs<ContinueResultUI>();
	_pResultUI->SetCallback([this]()
	{
		ChangeResultPhase(EventManager::Instance().GetEnergy());
	});
	// カメラ生成
	_pCamera = new Camera();
	// 各オブジェクトのインタラクト時のコールバック設定

}

void PhaseMain::OnCursorProc(Vector2 pos)
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

	// ステージオブジェクト
	// ワールド座標に変更
	Camera* camera = Camera::instance;
	Vector2 worldPos =  GetScreen2StagePos(pos, camera->GetHeight(), camera->GetPosition());
	BaseObject* stageObject = ObjectManager::Instance().FindPosObject(worldPos);
	if (stageObject != nullptr)
	{
		stageObject->OnCursor();
		InputManager::Instance().SetOnCursorObject(stageObject);
		return;
	}
	InputManager::Instance().SetOnCursorObject(nullptr);
}

void PhaseMain::LPushInputProc(Vector2 pos)
{
	// UIの入力


	// キャラクターの入力


	// ステージの入力

}

void PhaseMain::RPushInputProc(Vector2 pos)
{
	// カメラの移動
	_pCamera->RPushEvent(pos);
	// キャラクターが選択されているかで分岐

}

void PhaseMain::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	if (InputManager::Instance().IsLeftClick(pos)) return;
	// 範囲選択
	_pRangeSelect->SetActive(true);
	_pRangeSelect->SetPosition(pos + ((oldPos - pos) / 2));
	_pRangeSelect->SetSize(oldPos - pos);
}

void PhaseMain::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	_pCamera->RDrackEvent(pos);
}

void PhaseMain::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// ワールド座標に変更
	Camera* camera = Camera::instance;
	Vector2 worldPos =  GetScreen2StagePos(pos, camera->GetHeight(), camera->GetPosition());

	// クリックが離されたなら
	if (InputManager::Instance().IsLeftClick(pos))
	{
		// スクリーンUI
		BaseObject* object = ObjectManager::Instance().FindPosObject(pos);
		// スクリーンUIがないならワールド座標を渡してオブジェクト取得
		if (object == nullptr)
		{
			object = ObjectManager::Instance().FindPosObject(worldPos);
		}
		if (object != nullptr)
		{
			object->ClickEvent();
			return;
		}
		// ステージ外をクリック
		if (!StageManager::Instance().CheckPosOnStage(worldPos))
		{
			_pSelectOfficerList.clear();
			_pSelectOperationUI->SetActive(false);
			_pOfficerUI->SetActive(false);
			return;
		}
	}
	// ドラックが離されたなら
	else
	{
		_pRangeSelect->SetActive(false);
		// ワールド座標に変更
		Camera* camera = Camera::instance;
		Vector2 worldOldPos =  GetScreen2StagePos(oldPos, camera->GetHeight(), camera->GetPosition());
		// 中心座標と大きさを指定
		Vector2 centorPos = Vector2(worldPos + ((worldOldPos - worldPos) / 2));
		Vector2 size = worldOldPos - worldPos;
		// 職員の取得
		std::vector<BaseObject*> officerList = ObjectManager::Instance().FindRectAllObject(centorPos, size, ObjectType::CHARACTER);
		if (officerList.empty()) return;
		_pSelectOfficerList.clear();
		for (int i = 0, max = officerList.size(); i < max; i++)
		{
			OfficerPlayer* officer = dynamic_cast<OfficerPlayer*>(officerList[i]);
			if (officer == nullptr) continue;
			// 作業中ならスキップ
			if (officer->stateID == CharacterStateID::OPERATION) return;
			_pSelectOfficerList.push_back(officer);
		}
		return;
	}
}

void PhaseMain::RReleaseInputProc(Vector2 pos, Vector2 oldPos)
{

}

void PhaseMain::WheelRotInputProc(Vector2 pos, int rot)
{
	_pCamera->WheelEvent(rot);
}

void PhaseMain::EscapeInputProc()
{

}

void PhaseMain::ChangeResultPhase(int value)
{
	DataManager::Instance().SetEnergy(value);
	// 生存職員をデータに記録
	DataManager::Instance().SetOfficerData(OfficerManager::Instance().GetAliveOfficerData());
	ChangePhase(PhaseName::RESULT);
}