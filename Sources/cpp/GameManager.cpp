#include "../header/GameManager.h"

GameManager::GameManager()
{
	Init();

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
}

void GameManager::Proc()
{
	_pPhaseManager->Proc();
}

bool GameManager::GetGameEnd() { return _gameEnd; }