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

private:
	GameManager* _pGamemanager;
};

