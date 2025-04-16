#include "../header/PhaseMain.h"
#include "../header/StageCreator.h"
#include "../header/OfficerManager.h"
#include "../header/CameraController.h"
#include "../header/InputManager.h"

void PhaseMain::Init()
{
	// “ü—Í‚Ì‰Šú‰»
	pInputManager = new InputManager();

	_stageManager = new StageManager();
	_stageManager->CreateStage();
	_cameraController = new CameraController();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
}

bool PhaseMain::Proc()
{
	_cameraController->Update();
	// “ü—Íó•t

	// ‘I‘ğ‚³‚ê‚½‚ç

	return false;
}

void PhaseMain::InputProc()
{
	// “ü—Íˆ—
}