#pragma once
#include "BaseScene.h"
#include "InputManager.h"
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
private:
	/// <summary>
	/// ���N���b�N�̓��͏���
	/// </summary>
	void LPushInputProc(Vector2 pos);
};

