#pragma once
#include "BaseScene.h"
#include "InputManager.h"
/*
* Ishihara
* タイトルシーン
*/
class SceneTitle : public BaseScene
{
public:
	SceneTitle();
    ~SceneTitle();

    /// <summary>
    /// 初期化
    /// </summary>
    void Init();
private:
	/// <summary>
	/// 左クリックの入力処理
	/// </summary>
	void LPushInputProc(Vector2 pos);
};

