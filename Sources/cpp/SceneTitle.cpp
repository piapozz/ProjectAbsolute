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
	_inputManager->SetLPushCallback([this](Vector2 pos) { this->LReleaseInputProc(pos); });
}

void SceneTitle::Proc()
{
	DrawString (0, 0, "Title", GetColor (255, 255, 255));
	_inputManager->ExecuteCallback();
}

void SceneTitle::Draw()
{

}

void SceneTitle::LReleaseInputProc(Vector2 pos)
{
	// �V�[���ύX�R�[���o�b�N�����s
	if (ChangeScene != nullptr) ChangeScene(SceneName::MAIN);
}

