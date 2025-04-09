#include "../header/SceneTitle.h"

SceneTitle::SceneTitle()
{
    _titleLogoHandle = LoadGraph("Resources/Signal_Logo.png");
}

SceneTitle::~SceneTitle()
{

}

void SceneTitle::Init()
{
    // ŽžŠÔŒv‘ª—p
    startTime = GetNowCount();
}

void SceneTitle::Proc()
{

}

int SceneTitle::CheckChangeScene() 
{
    return 0;
}

void SceneTitle::Draw()
{

}