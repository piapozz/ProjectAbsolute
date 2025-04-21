#include "../header/SceneTitle.h"

SceneTitle::SceneTitle()
{

}

SceneTitle::~SceneTitle()
{
	_inputManager = nullptr;
	delete _inputManager;
}

void SceneTitle::Init()
{
	// 入力受付クラスを生成
	_inputManager = new InputManager();
	_inputManager->SetLPushCallback([this](Vector2 pos) { this->LPushInputProc(pos); });
}

void SceneTitle::Proc()
{
	DrawString (0, 0, "Title", GetColor (255, 255, 255));
	_inputManager->ExecuteCallback();
}

void SceneTitle::Draw()
{

}

void SceneTitle::LPushInputProc(Vector2 pos)
{
	// シーン変更コールバックを実行
	if (ChangeScene != nullptr) ChangeScene(SceneName::MAIN);
}

