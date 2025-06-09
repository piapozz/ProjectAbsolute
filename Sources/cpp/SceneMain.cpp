#include "../header/SceneMain.h"
#include "../header/GameManager.h"
#include "../header/ObjectFactory.h"

SceneMain::SceneMain()
{

}

SceneMain::~SceneMain()
{
	ObjectFactory::Instance();
	delete _pGamemanager;
}

void SceneMain::Init()
{
	_pGamemanager = new GameManager();
	_pGamemanager->Init();
}