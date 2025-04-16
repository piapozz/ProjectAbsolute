#include "../header/PhaseMain.h"
#include "../header/StageCreator.h"
#include "../header/OfficerManager.h"
#include "../header/CameraController.h"

void PhaseMain::Init()
{
	// ���͎�t�N���X�𐶐�

	_stageCreator = new StageCreator();
	_stageCreator->CreateStage();
	_cameraController = new CameraController();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
}

bool PhaseMain::Proc()
{
	_cameraController->Update();
	// ���͎�t

	// �I�����ꂽ��

	return false;
}

void PhaseMain::InputProc()
{
	// ���͏���
}