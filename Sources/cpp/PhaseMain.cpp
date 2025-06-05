#include "../header/PhaseMain.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/CameraController.h"
#include "../header/InputManager.h"
#include "../header/Entity_E000.h"
#include "../header/EventManager.h"
#include "../header/UIScreenButton.h"
#include "../header/UIManager.h"
#include "../header/BaseOfficer.h"
#include "../header/SecureRoom.h"
#include "../header/ObjectFactory.h"

std::vector<OfficerPlayer*>& PhaseMain::GetSelectOfficerList(){ return _pSelectOfficerList; }
std::vector<OfficerPlayer*> PhaseMain::_pSelectOfficerList;

void PhaseMain::Init()
{
	// 入力の初期化
	_pCameraController = new CameraController();
	pInputManager = new InputManager();
	pInputManager->SetOnCursorCallback([this](Vector2 pos){ this->OnCursorProc(pos); });
	pInputManager->SetLPushCallback([this](Vector2 pos){ this->LPushInputProc(pos); });
	pInputManager->SetLDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->LDrackInputProc(pos, oldPos); });
	pInputManager->SetLReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->LReleaseInputProc(pos, oldPos); });
	pInputManager->SetRPushCallback([this](Vector2 pos){ this->RPushInputProc(pos); });
	pInputManager->SetRDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->RDrackInputProc(pos, oldPos); });
	pInputManager->SetRReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->RReleaseInputProc(pos, oldPos); });
	pInputManager->SetWheelRotCallback([this](Vector2 pos, int rot){ this->WheelRotInputProc(pos, rot); });
	pInputManager->SetEscapeCallback([this](){ this->EscapeInputProc(); });

	_pStageManager = new StageManager();
	_pStageManager->SetStageData(_stageData);
	_pStageManager->CreateStage();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
	BaseEntity* addEntity = ObjectFactory::Instance().Create<Entity_E000>();
	_pStageManager->SetEntity(addEntity, 0);
	_pEventManager = new EventManager();
	_pEventManager->Init();
	SecureRoom::EndOperationEvent = [this](int successCount)
	{
		// 作業が終了したら、エネルギーを追加
		_pEventManager->AddEnergy(successCount);
	};
	_pRangeSelect = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(Vector2::zero(), Vector2::zero(), false);
	_pRangeSelect->SetLayer(Layer::NONE_DRAW);
	_pUIManager = new UIManager();
	// 各オブジェクトのインタラクト時のコールバック設定

}

bool PhaseMain::Proc()
{
	// 入力処理
	pInputManager->ExecuteCallback();
	_pCameraController->UpdateCamera();

	return false;
}

void PhaseMain::OnCursorProc(Vector2 pos)
{
	// 以前乗っていたオブジェクトを乗っていなくする
	BaseObject* onCursorObj = pInputManager->GetOnCursorObject();
	if (onCursorObj != nullptr)
	{
		onCursorObj->NotOnCursor();
	}

	// ワールド座標に変更
	Vector2 worldPos = _pCameraController->GetScreen2StagePos(pos);

	// スクリーンUI
	// UIの取得
	BaseObject* ScreenUI = ObjectManager::Instance().FindPosObject(pos);
	if (ScreenUI != nullptr)
	{
		ScreenUI->OnCursor();
		pInputManager->SetOnCursorObject(ScreenUI);
		return;
	}
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
	_pCameraController->RPushEvent(pos);
	// キャラクターが選択されているかで分岐

}

void PhaseMain::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	if (pInputManager->IsLeftClick(pos)) return;
	// 範囲選択
	_pRangeSelect->SetLayer(Layer::NONE_INTERACT);
	_pRangeSelect->SetPosition(pos + ((oldPos - pos) / 2));
	_pRangeSelect->SetSize(oldPos - pos);
}

void PhaseMain::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	_pCameraController->RDrackEvent(pos);
}

void PhaseMain::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// ワールド座標に変更
	Vector2 worldPos = _pCameraController->GetScreen2StagePos(pos);

	// クリックが離されたなら
	if (pInputManager->IsLeftClick(pos))
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
		if (!_pStageManager->CheckPosOnStage(worldPos))
		{
			_pSelectOfficerList.clear();
			_pUIManager->SetActiveOperationUI(false);

			return;
		}
	}
	// ドラックが離されたなら
	else
	{
		_pRangeSelect->SetLayer(Layer::NONE_DRAW);
		// ワールド座標に変更
		Vector2 worldOldPos = _pCameraController->GetScreen2StagePos(oldPos);
		// 中心座標と大きさを指定
		Vector2 centorPos = Vector2(worldPos + ((worldOldPos - worldPos) / 2));
		Vector2 size = worldOldPos - worldPos;
		// 職員の取得
		std::vector<BaseObject*> officerList = ObjectManager::Instance().FindRectAllObject(centorPos, size, ObjectType::CHARACTER);
		if (officerList.empty()) return;
		_pSelectOfficerList.clear();
		for (int i = 0, max = officerList.size(); i < max; i++)
		{
			OfficerPlayer* officer = static_cast<OfficerPlayer*>(officerList[i]);
			_pSelectOfficerList.push_back(officer);
			officer->ClickEvent();
		}
		return;
	}
}

void PhaseMain::RReleaseInputProc(Vector2 pos, Vector2 oldPos)
{

}

void PhaseMain::WheelRotInputProc(Vector2 pos, int rot)
{
	_pCameraController->WheelEvent(rot);
}

void PhaseMain::EscapeInputProc()
{

}