#include "../header/GameManager.h"

GameManager::GameManager()
{
	Init();
}

GameManager::~GameManager()
{

}

void GameManager::Init()
{
	_gameEnd = false;
}

void GameManager::Proc()
{

}

bool GameManager::GetGameEnd() { return _gameEnd; }