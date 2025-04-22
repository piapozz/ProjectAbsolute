#include "../header/PhaseMain.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/CameraController.h"
#include "../header/InputManager.h"

void PhaseMain::Init()
{
	// 入力の初期化
	_pCameraController = new CameraController();
	pInputManager = new InputManager();
	pInputManager->SetLPushCallback([this](Vector2 pos){ this->LPushInputProc(pos); });
	pInputManager->SetLDrackCallback([this](Vector2 pos){ this->LDrackInputProc(pos); });
	pInputManager->SetLReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->LReleaseInputProc(pos, oldPos); });
	pInputManager->SetRPushCallback([this](Vector2 pos){ this->RPushInputProc(pos); });
	pInputManager->SetRDrackCallback([this](Vector2 pos){ this->RDrackInputProc(pos); });
	pInputManager->SetRReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->RReleaseInputProc(pos, oldPos); });
	pInputManager->SetWheelRotCallback([this](Vector2 pos, int rot){ this->WheelRotInputProc(pos, rot); });
	pInputManager->SetEscapeCallback([this](){ this->EscapeInputProc(); });

	_pStageManager = new StageManager();
	_pStageManager->SetStageData(_stageData);
	_pStageManager->CreateStage();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
}

bool PhaseMain::Proc()
{
	// 入力処理
	pInputManager->ExecuteCallback();

	return false;
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

void PhaseMain::LDrackInputProc(Vector2 pos)
{

}

void PhaseMain::RDrackInputProc(Vector2 pos)
{
	_pCameraController->RDrackEvent(pos);
}

void PhaseMain::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// ワールド座標に変更
	Vector2 worldPos = GetScreen2StagePos(pos);

	// UI
	// UIの取得
	BaseObject* UI = ObjectManager::FindPosObject(worldPos, ObjectType::UI);
	if (UI != nullptr)
	{
		UI->ClickEvent();
		return;
	}

	// キャラクター
	// 職員の取得
	BaseObject* officer = ObjectManager::FindPosObject(worldPos, ObjectType::CHARACTER);
	if (officer != nullptr)
	{
		_pPlayerOfficerList.push_back(static_cast<OfficerPlayer*>(officer));
		officer->ClickEvent();
		return;
	}

	// ステージの取得
	BaseObject* section = ObjectManager::FindPosObject(worldPos, ObjectType::SECTION);
	if (_pPlayerOfficerList.empty()) return;
	
	if (static_cast<SecureRoom*>(section) != nullptr)
	{
		// 収容所の取得
		SecureRoom* secureRoom = static_cast<SecureRoom*>(section);
		secureRoom->ClickEvent();
		//_pPlayerOfficerList[0]->SetSecureRoom(secureRoom);
		return;
	}
	// 移動
	if (!_pStageManager->CheckPosOnStage(worldPos)) return;
	std::vector<Vector2> routeList = StageManager::FindPath(_pPlayerOfficerList[0]->GetPosition(), worldPos);
	StateArgs* args = new StateArgs();
	args->targetPosList = routeList;
	_pPlayerOfficerList[0]->ChangeState(OfficerStateID::OFFICER_MOVE, args);
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

Vector2 PhaseMain::GetScreen2StagePos(Vector2 screenPos)
{
	// 拡縮と中心座標から変換
	float heightSize = _pCameraController->GetHeightSize();
	Vector2 stageCentorPos = _pCameraController->GetCameraPos();
	float ratio = heightSize / WINDOW_HEIGHT;
	Vector2 screenCentor = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2;
	// スクリーンの中心座標からの距離に拡縮をかけてステージの中心座標から求める
	Vector2 screenDistance = Vector2(screenPos.x - screenCentor.x, screenCentor.y - screenPos.y);
	return Vector2(stageCentorPos + screenDistance * ratio);
}