#pragma once
#include "BaseScene.h"
/*
* Ishihara
* �^�C�g���V�[��
*/
class SceneTitle : public BaseScene
{
public:
    SceneTitle();
    ~SceneTitle();

    /// <summary>
    /// ������
    /// </summary>
    void Init();
    /// <summary>
    /// ����
    /// </summary>
    void Proc();
    /// <summary>
    /// �`��
    /// </summary>
    void Draw();
};

