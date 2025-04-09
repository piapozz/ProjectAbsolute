#pragma once
#include "../header/BaseScene.h"

class SceneMain :
    public BaseScene
{
private:

    int sceneName = BaseScene::SceneName::NONE;

public:

    SceneMain();
    ~SceneMain();


    void Init();       // ‰Šú‰»

    void Proc();       // ˆ—

    void Draw();       // •`‰æ

    int CheckChangeScene();
};

