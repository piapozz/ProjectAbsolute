#pragma once
#include "../header/Const.h"
/*
* Ishihara
* �I�u�W�F�N�g�̊Ǘ�
*/
class BaseObject;
class ObjectManager
{
public:
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
private:
	// �I�u�W�F�N�g�̃��X�g
	std::vector<BaseObject*> _objectList;
};

