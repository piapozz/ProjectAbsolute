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
	ObjectManager() {}
	~ObjectManager() {}

	/// <summary>
	/// ������
	/// </summary>
	static void Init();
	/// <summary>
	/// �X�V
	/// </summary>
	static void Update();
	/// <summary>
	/// �`��
	/// </summary>
	static void Draw();
	/// <summary>
	/// �I�u�W�F�N�g�̒ǉ�
	/// </summary>
	static void AddObject(BaseObject* obj);
	/// <summary>
	/// �I�u�W�F�N�g�̍폜
	/// </summary>
	static void RemoveObject(BaseObject* obj);
	// �I�u�W�F�N�g�̃��X�g
	static std::vector<BaseObject*> _objectList;
};

