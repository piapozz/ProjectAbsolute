#pragma once
#include "BaseObject.h"
/*
* Ishihara
* �L�����N�^�[�̊��
*/
class BaseCharacter: public BaseObject
{
public:
	BaseCharacter() {}
	BaseCharacter(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseCharacter(Layer setLayer,int setDrawHandle)
		: BaseObject(setLayer,setDrawHandle) {}
	BaseCharacter(const BaseCharacter& obj)
		: BaseObject(obj) {}
	~BaseCharacter() {}

	/// <summary>
	/// ������
	/// </summary>
	void Init() override;
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	void Proc() override;
	/// <summary>
	/// �`��
	/// </summary>
	void Draw() override;
	/// <summary>
	/// �j��
	/// </summary>
	void Teardown() override;
	// �ړ�
	// �U��
	// ���S
	// ���

protected:
	// �U����
	int attack;
	// �U������
	Type attackType;
	// �h��{��
	float defenseRatio[(int)Type::MAX];
	int health;
	// �ő�̗�
	int maxHealth;
};

