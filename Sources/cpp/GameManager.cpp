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
	_gameEnd = false;
	_pPhaseManager = new PhaseManager();
	_pPhaseManager->Init();
}

bool GameManager::GetGameEnd() { return _gameEnd; }