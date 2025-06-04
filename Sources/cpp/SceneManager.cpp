#include "../header/SceneManager.h"

SceneManager::SceneManager() 
{
	_scene = nullptr;
}

SceneManager::~SceneManager() 
{
	delete _scene;
}

void SceneManager::Init() 
{

}

void SceneManager::Proc() 
{
	_scene->Proc();
}

void SceneManager::Draw() 
{
	_scene->Draw();
}

void SceneManager::ChangeScene(SceneName scene)
{
	if (scene == SceneName::INVALID) return;
	// ���݂̃V�[�����󂶂�Ȃ�������A�V�[���̏���j������
	delete(_scene);

	// �����̃V�[���ɐ؂�ւ���
	switch (scene)
	{
	case SceneName::TITLE:
		_scene = new SceneTitle();
		break;
	case SceneName::MAIN:
		_scene = new SceneMain();
		break;
	case SceneName::EXIT:
		DxLib_End();
		return;
	default:
		break;
	}
	// �����������Ă���
	_scene->Init();
	// �R�[���o�b�N��ݒ�
	_scene->SetCallback([this](SceneName nextScene) { this->ChangeScene(nextScene); });
}