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
	/// <summary>
	/// ���C���Q�[���V�[���ɕύX
	/// </summary>
	void ChangeMainGameScene();
    
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

};

