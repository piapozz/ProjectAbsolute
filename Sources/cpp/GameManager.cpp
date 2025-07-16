#include "../header/GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
	_pPhaseManager->Teardown();
	delete _pPhaseManager;
}

void GameManager::Init()
{
	_pPhaseManager = new PhaseManager();
	_pPhaseManager->SetCallback(_ChangeScene);
	_pPhaseManager->Init();
}