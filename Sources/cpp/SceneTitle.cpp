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
	// ���͎�t�N���X�𐶐�
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
	// �V�[���ύX�R�[���o�b�N�����s
	if (ChangeScene != nullptr) ChangeScene(SceneName::MAIN);
}

