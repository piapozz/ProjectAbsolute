#pragma once
#include "../header/BaseScene.h"

#include "../header/SceneTitle.h"
#include "../header/SceneMain.h"

/*
* Ishihara
* シーンの管理
*/
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	
	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// 処理
	/// </summary>
	void Proc();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	/// <summary>
	/// シーンの切り替え
	/// </summary>
	/// <param name="scene"></param>
	void ChangeScene(SceneName scene);
private:
	// シーンの情報を格納
	BaseScene* _scene;
};

