#include "../header/PhaseMain.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/CameraController.h"
#include "../header/InputManager.h"

void PhaseMain::Init()
{
	// 入力の初期化
	pInputManager = new InputManager();
	pInputManager->SetLClickCallback([this](Vector2 pos, Vector2 oldPos){ this->LClickInputProc(pos, oldPos); });

	_pStageManager = new StageManager();
	_pStageManager->SetStageData(_stageData);
	_pStageManager->CreateStage();
	_pCameraController = new CameraController();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
}

bool PhaseMain::Proc()
{
	_pCameraController->Update();
	// 入力処理
	pInputManager->ExecuteCallback();

	return false;
}

void PhaseMain::LClickInputProc(Vector2 pos, Vector2 oldPos)
{
	// ワールド座標に変更
	Vector2 worldPos = GetScreen2StagePos(pos);
	Vector2 worldOldPos = GetScreen2StagePos(oldPos);


}

void PhaseMain::RClickInputProc(Vector2 pos, Vector2 oldPos)
{

}

void PhaseMain::EscapeInputProc()
{

}

Vector2 PhaseMain::GetScreen2StagePos(Vector2 screenPos)
{
	// 拡縮と中心座標から変換
	float heightSize = _pCameraController->GetHeightSize();
	Vector2 centorPos = _pCameraController->GetCameraPos();
	// 中心座標＝ステージ座標

	float ratio = heightSize / WINDOW_HEIGHT;
	Vector2 screenCentor = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2;
	Vector2 screenDistance = Vector2(screenPos.x - screenCentor.x, screenCentor.y - screenPos.y);

	return Vector2(centorPos + screenDistance * ratio);
}