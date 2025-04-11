#include "../header/SceneManager.h"

SceneManager::SceneManager() 
{
	_scene = nullptr;
}

SceneManager::~SceneManager() 
{
	if (_exitFlag)return;

	delete _scene;
}

void SceneManager::Init() 
{
	_scene->Init();
}

void SceneManager::Proc() 
{
	if (_exitFlag)return;

	_scene->Proc();
	ChangeScene(_scene->CheckChangeScene());
}

void SceneManager::Draw() 
{
	if (_exitFlag) return;
		
	_scene->Draw();
}

void SceneManager::ChangeScene(int scene)
{
	if (scene == BaseScene::NONE) return;

	// 現在のシーンが空じゃなかったら、シーンの情報を破棄する
	delete(_scene);

	// 引数のシーンに切り替える
	switch (scene)
	{
	case BaseScene::GAME_TITLE:
		_scene = new SceneTitle();
		break;
	case BaseScene::GAME_MAIN:
		_scene = new SceneMain();
		break;
	case BaseScene::GAME_EXIT:
		_exitFlag = true;
		DxLib_End();
		return;
	default:
		break;
	}

	// 初期化をしておく
	_scene->Init();
	SetFontSize(20);
}