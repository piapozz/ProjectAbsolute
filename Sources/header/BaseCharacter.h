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
	virtual void Init();
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

	/// <summary>
	/// �_���[�W����
	/// </summary>
	/// <param name="strength"></param>
	/// <param name="damageType"></param>
	/// <returns></returns>
	virtual int TakeDamege(int strength, Type damageType) { return -1; }
	/// <summary>
	/// �̗͌�������
	/// </summary>
	/// <param name="decreaseValue"></param>
	void DecreaseHealth(int decreaseValue);

	int GetHealth(){ return health; }
	void SetHealth(int value){ health = value; }

protected:
	// �U����
	int attack;
	// �U������
	Type attackType;
	// �h��{��
	float defenseRatio[(int)Type::MAX];
	// �̗�
	int health;
	// �ő�̗�
	int maxHealth;
};

