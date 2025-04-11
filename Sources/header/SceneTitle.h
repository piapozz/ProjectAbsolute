#pragma once
#include "BaseScene.h"
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
};

