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
    /// <summary>
    /// 処理
    /// </summary>
    void Proc();
    /// <summary>
    /// 描画
    /// </summary>
    void Draw();
private:
	// 入力受付クラス
	InputManager* _inputManager;

	/// <summary>
	/// 左クリックの入力処理
	/// </summary>
	void LPushInputProc(Vector2 pos);
};

