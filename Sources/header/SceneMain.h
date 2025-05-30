#pragma once
#include "../header/BaseScene.h"
class GameManager;
/*
* Ishihara
* メインシーン
*/
class SceneMain : public BaseScene
{
public:
    SceneMain();
    ~SceneMain();

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
	GameManager* _pGamemanager;
};

