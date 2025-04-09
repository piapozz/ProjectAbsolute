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


    void Init();       // ������

    void Proc();       // ����

    void Draw();       // �`��

    int CheckChangeScene();
};

