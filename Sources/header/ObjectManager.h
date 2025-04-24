#pragma once
#include "Const.h"
#include <vector>
#include "BaseObject.h"
/*
* Ishihara
* �I�u�W�F�N�g�̊Ǘ�
*/
class ObjectManager
{
public:
	static ObjectManager* instance;

	ObjectManager() {}
	~ObjectManager() {}

	/// <summary>
	/// ������
	/// </summary>
	void Init();
	/// <summary>
	/// �X�V
	/// </summary>
	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	/// <summary>
	/// �I�u�W�F�N�g�̒ǉ�
	/// </summary>
	void AddObject(BaseObject* obj);
	/// <summary>
	/// �I�u�W�F�N�g�̍폜
	/// </summary>
	void RemoveObject(BaseObject* obj);
	/// <summary>
	/// �I�u�W�F�N�g�̑S�폜
	/// </summary>
	void AllClear();
	/// <summary>
	/// �I�u�W�F�N�g�̌���
	/// </summary>
	/// <returns></returns>
	BaseObject* FindPosObject(Vector2 pos, ObjectType type);
	/// <summary>
	/// �Q�[�����x�̕ύX
	/// </summary>
	/// <param name="setGameSpeed"></param>
	void ChangeGameSpeed(int setGameSpeed){
		_gameSpeed = setGameSpeed;
	}
private:
	// �I�u�W�F�N�g�̃��X�g
	std::vector<std::vector<BaseObject*>> _objectList;
	// �Q�[���X�s�[�h
	int _gameSpeed;
};

