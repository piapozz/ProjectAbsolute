#include "../header/SceneTitle.h"

SceneTitle::SceneTitle()
{

}

SceneTitle::~SceneTitle()
{
	delete _inputManager;
}

void SceneTitle::Init()
{
	// 入力受付クラスを生成
	_inputManager = new InputManager();
	_inputManager->SetLClickCallback([this](Vector2 pos, Vector2 oldPos) { this->LClickInputProc(pos, oldPos); });
}

void SceneTitle::Proc()
{
	DrawString (0, 0, "Title", GetColor (255, 255, 255));
	_inputManager->ExecuteCallback();
}

void SceneTitle::Draw()
{

}

void SceneTitle::LClickInputProc(Vector2 pos, Vector2 oldPos)
{
	// シーン変更コールバックを実行
	if (ChangeScene != nullptr) ChangeScene(SceneName::MAIN);
}

