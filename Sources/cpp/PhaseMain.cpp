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
	BaseEntity* addEntity = new Entity_E000();
	addEntity->Init();
	_pStageManager->SetEntity(addEntity, 0);
	_pEventManager = new EventManager();
	_pEventManager->Init();
	SecureRoom::EndOperationEvent = [this](int successCount)
	{
		// 作業が終了したら、エネルギーを追加
		_pEventManager->AddEnergy(successCount);
	};
	_pRangeSelect = new UIScreenButton();
	_pRangeSelect->Init(Vector2::zero(), Vector2::zero(), false);
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
	BaseObject* ScreenUI = ObjectManager::instance->FindPosObject(pos, ObjectType::SCREEN_UI);
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
		// UIの取得
		BaseObject* ScreenUI = ObjectManager::instance->FindPosObject(pos, ObjectType::SCREEN_UI);
		if (ScreenUI != nullptr)
		{
			ScreenUI->ClickEvent();
			return;
		}
		// UI
		// UIの取得
		BaseObject* UI = ObjectManager::instance->FindPosObject(worldPos, ObjectType::UI);
		if (UI != nullptr)
		{
			UI->ClickEvent();
			return;
		}
		// キャラクター
		// 職員の取得
		BaseObject* officer = ObjectManager::instance->FindPosObject(worldPos, ObjectType::CHARACTER);
		if (officer != nullptr)
		{
			_pSelectOfficerList.clear();
			_pSelectOfficerList.push_back(static_cast<OfficerPlayer*>(officer));
			officer->ClickEvent();
			return;
		}
		// ステージの取得
		BaseObject* section = ObjectManager::instance->FindPosObject(worldPos, ObjectType::SECTION);
		if (_pSelectOfficerList.empty()) return;

		if (dynamic_cast<SecureRoom*>(section) != nullptr)
		{
			// 収容所の取得
			SecureRoom* secureRoom = static_cast<SecureRoom*>(section);
			secureRoom->ClickEvent();
			secureRoom->SetInteractOfficer(_pSelectOfficerList[0]);
		}
		// ステージ外をクリック
		if (!_pStageManager->CheckPosOnStage(worldPos))
		{
			_pSelectOfficerList.clear();
			return;
		}
		// キャラ移動が可能なら移動
		if (_pSelectOfficerList[0]->GetImpossible())
		{
			_pSelectOfficerList[0]->ChangeMoveState(worldPos);
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
		std::vector<BaseObject*> officerList = ObjectManager::instance->FindRectObject(centorPos, size, ObjectType::CHARACTER);
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