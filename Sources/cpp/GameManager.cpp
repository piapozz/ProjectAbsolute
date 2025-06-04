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
	_pObjectManager = new ObjectManager();
	_pObjectManager->Init();
	_gameEnd = false;
	_pPhaseManager = new PhaseManager();
	_pPhaseManager->Init();
}

void GameManager::Proc()
{
	_pPhaseManager->Proc();
}

bool GameManager::GetGameEnd() { return _gameEnd; }