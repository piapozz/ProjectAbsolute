#pragma once
#include "../header/BaseScene.h"
class PhaseManager;
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
    /// <summary>
    /// ����
    /// </summary>
    void Proc();
    /// <summary>
    /// �`��
    /// </summary>
    void Draw();

private:
	PhaseManager* _phaseManager;
};

