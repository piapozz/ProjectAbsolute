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
    /// <summary>
    /// ����
    /// </summary>
    void Proc();
    /// <summary>
    /// �`��
    /// </summary>
    void Draw();
private:
	// ���͎�t�N���X
	InputManager* _inputManager;

	/// <summary>
	/// ���N���b�N�̓��͏���
	/// </summary>
	void LPushInputProc(Vector2 pos);
};

