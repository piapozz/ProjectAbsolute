#include "../header/SceneTitle.h"

SceneTitle::SceneTitle()
{

}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{

}

void SceneTitle::LPushInputProc(Vector2 pos)
{
	// �V�[���ύX�R�[���o�b�N�����s
	if (ChangeScene != nullptr) ChangeScene(SceneName::MAIN);
}

