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
	/// <summary>
	/// �I�u�W�F�N�g�̑S�폜
	/// </summary>
	static void AllClear();
	/// <summary>
	/// �I�u�W�F�N�g�̌���
	/// </summary>
	/// <returns></returns>
	static BaseObject* FindPosObject(Vector2 pos, ObjectType type);
	// �I�u�W�F�N�g�̃��X�g
	static std::vector<std::vector<BaseObject*>> _objectList;
};

