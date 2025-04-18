#pragma once
#include "../header/BaseScene.h"
class GameManager;
/*
* Ishihara
* ƒƒCƒ“ƒV[ƒ“
*/
class SceneMain : public BaseScene
{
public:
    SceneMain();
    ~SceneMain();

    /// <summary>
    /// ‰Šú‰»
    /// </summary>
    void Init();
    /// <summary>
    /// ˆ—
    /// </summary>
    void Proc();
    /// <summary>
    /// •`‰æ
    /// </summary>
    void Draw();

private:
	GameManager* _pGamemanager;
};

