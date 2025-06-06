#pragma once
#include "BaseObject.h"
#include "../header/RouteSearcher.h"
#include "../header/StateArgs.h"
#include "../header/BaseSection.h"

class BaseCharacterState;
class BaseAttack;

/*
* Ishihara
* �L�����N�^�[�̊��
*/
class BaseCharacter: public BaseObject
{
public:
	struct AttackStatus
	{
		// �U����
		int attack;
		// �U������
		Type damageType;
	};

	BaseCharacter() {}
	BaseCharacter(LayerSetting layerSetting) {
		Init(layerSetting);
	}
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
	virtual void Init(LayerSetting layerSetting);
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
	virtual void TakeDamage(int strength, Type damageType)
	{
		float index;
		index = strength * defenseRatio[(int)damageType];
		DecreaseHealth(ceil(index));
	}
	/// <summary>
	/// ���ֈړ�����
	/// </summary>
	/// <param name="targetSection"></param>
	/// <returns></returns>
	bool Move(BaseSection* targetSection);
	/// <summary>
	/// �ׂ������W�Ɉړ�����
	/// </summary>
	/// <param name="targetPosition"></param>
	/// <returns></returns>
	bool Move(Vector2 targetPosition);
	/// <summary>
	/// �̗͌�������
	/// </summary>
	/// <param name="decreaseValue"></param>
	void DecreaseHealth(int decreaseValue);
	/// <summary>
	/// �L�����N�^�[�̃X�e�[�g�̐؂�ւ�
	/// </summary>
	/// <param name="stateID"></param>
	/// <param name="args"></param>
	void ChangeState(CharacterStateID stateID, StateArgs* args = nullptr);
	/// <summary>
	/// �ړ��X�e�[�g���ȒP�ɐ؂�ւ���֐�
	/// </summary>
	/// <param name="targetPos"></param>
	/// <param name="secureRoom"></param>
	void ChangeMoveState(BaseSection* targetSection);

	Vector2 GetPosition(){ return position; }
	BaseSection* GetPastPosition(){ return pastRoom; }
	void SetAttackStatus(AttackStatus attackStatus){ _attackStatus = attackStatus; }
	AttackStatus GetAttackStatus() { return _attackStatus; }
	void SetHealth(int value){ health = value; }
	int GetHealth(){ return health; }
	void SetImpossible(bool flag){ impossible = flag; }
	bool GetImpossible(){ return impossible; }
	void SetGroup(CharacterGroup groupType){ _groupType = groupType; }
	CharacterGroup GetGroup(){ return _groupType; }
	void SetAttack(BaseAttack* baseAttack){ characterAttack = baseAttack; }
	BaseAttack* GetAttack(){ return characterAttack; }

	// �ߋ��̈ʒu
	BaseSection* pastRoom;
	BaseCharacterState* pCharacterState;
	CharacterStateID stateID;
	BaseAttack* characterAttack;
	unsigned int color;

protected:
	// �U���̏��
	AttackStatus _attackStatus;
	// �h��{��
	float defenseRatio[(int)Type::MAX];
	// �̗�
	int health;
	// �ő�̗�
	int maxHealth;
	// �X�e�[�g��J�ڂł��邩
	bool impossible;
	// �L�����N�^�[�̐w�c
	CharacterGroup _groupType;

private:

};

