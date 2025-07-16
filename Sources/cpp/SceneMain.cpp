#include "../header/SceneMain.h"
#include "../header/GameManager.h"
#include "../header/ObjectFactory.h"

SceneMain::SceneMain()
{

}

SceneMain::~SceneMain()
{
	delete _pGameManager;
}

void SceneMain::Init()
{
	_pGameManager = new GameManager();
	_pGameManager->SetChangeSceneCallback(ChangeScene);
	_pGameManager->Init();
}