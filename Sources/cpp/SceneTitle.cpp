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
	// シーン変更コールバックを実行
	if (ChangeScene != nullptr) ChangeScene(SceneName::MAIN);
}

