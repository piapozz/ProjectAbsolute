#include "../header/SceneMain.h"
#include "../header/PhaseManager.h"

SceneMain::SceneMain()
{

}

SceneMain::~SceneMain()
{

}

void SceneMain::Init()
{
	_phaseManager = new PhaseManager();
}

void SceneMain::Proc()
{
	DrawString (0, 0, "Main", GetColor (255, 255, 255));
	_phaseManager->Proc();
}

void SceneMain::Draw()
{

}