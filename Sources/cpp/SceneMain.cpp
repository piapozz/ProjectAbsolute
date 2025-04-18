#include "../header/SceneMain.h"
#include "../header/GameManager.h"

SceneMain::SceneMain()
{

}

SceneMain::~SceneMain()
{
	delete _pGamemanager;
}

void SceneMain::Init()
{
	_pGamemanager = new GameManager();
	_pGamemanager->Init();
}

void SceneMain::Proc()
{
	DrawString (0, 0, "Main", GetColor (255, 255, 255));
	_pGamemanager->Proc();
}

void SceneMain::Draw()
{

}