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
	_inputManager->SetLClickCallback([this](void) { this->ChangeMainGameScene(); });
}

void SceneTitle::Proc()
{
	DrawString (0, 0, "Title", GetColor (255, 255, 255));
	_inputManager->OnClick(InputManager::MouseButton::LEFT_CLICK);
}

void SceneTitle::Draw()
{

}

void SceneTitle::ChangeMainGameScene()
{
	SceneName scene = SceneName::MAIN;
	// シーン変更コールバックを実行
	if (ChangeScene != nullptr) ChangeScene(scene);
}