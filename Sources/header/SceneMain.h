#pragma once
#include "../header/BaseScene.h"
class GameManager;
/*
* Ishihara
* ���C���V�[��
*/
class SceneMain : public BaseScene
{
public:
    SceneMain();
    ~SceneMain();

    /// <summary>
    /// ������
    /// </summary>
    void Init();

private:
	GameManager* _pGamemanager;
};

