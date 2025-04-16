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
	// ���͎�t�N���X�𐶐�
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
	// �V�[���ύX�R�[���o�b�N�����s
	if (ChangeScene != nullptr) ChangeScene(scene);
}