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
	// �V�[���ύX�R�[���o�b�N�����s
	if (ChangeScene != nullptr) ChangeScene(SceneName::MAIN);
}

