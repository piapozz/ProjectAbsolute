#include "../header/PhaseMain.h"
#include "../header/StageCreator.h"
#include "../header/OfficerManager.h"
#include "../header/CameraController.h"

void PhaseMain::Init()
{
	// 入力受付クラスを生成

	_stageCreator = new StageCreator();
	_stageCreator->CreateStage();
	_cameraController = new CameraController();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
}

bool PhaseMain::Proc()
{
	_cameraController->Update();
	// 入力受付

	// 選択されたら

	return false;
}

void PhaseMain::InputProc()
{
	// 入力処理
}