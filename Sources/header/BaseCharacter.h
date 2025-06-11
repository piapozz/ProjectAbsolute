#pragma once
#include "BaseObject.h"
#include "../header/RouteSearcher.h"
#include "../header/StateArgs.h"
#include "../header/BaseSection.h"

class BaseCharacterState;
class AIController;
class BaseAttack;
class ITargetSelector;

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

	struct AttackAction
	{
		// �Ώۂ̑I����@
		ITargetSelector* targetSelector;
		// �U���̎��
		BaseAttack* characterAttack;
		// �U���̎˒�
		float attackRange;
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
	//bool Move(BaseSection* targetSection, float speed);
	/// <summary>
	/// �ׂ������W�Ɉړ�����
	/// </summary>
	/// <param name="targetPosition"></param>
	/// <returns></returns>
	//bool Move(Vector2 targetPosition, float speed);
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
	/// �ړ��X�e�[�g�ɖړI�̕������g���Đ؂�ւ���
	/// </summary>
	/// <param name="targetPos"></param>
	/// <param name="secureRoom"></param>
	void ChangeMoveState(BaseSection* targetSection, CharacterStateID nextStateID = CharacterStateID::IDLE);
	/// <summary>
	/// �ړ��X�e�[�g�ɍ��W���g���Đ؂�ւ���
	/// </summary>
	/// <param name="targetPosition"></param>
	/// <param name="nextStateID"></param>
	void ChangeMoveState(Vector2 targetPosition, CharacterStateID nextStateID = CharacterStateID::IDLE);

	inline Vector2 GetPosition(){ return position; }
	inline BaseSection* GetPastPosition(){ return pastRoom; }
	inline AttackStatus GetAttackStatus() { return _attackStatus; }
	inline int GetHealth(){ return health; }
	inline bool GetImpossible(){ return impossible; }
	inline CharacterGroup GetGroup(){ return _groupType; }
	inline std::vector<AttackAction*> GetAttackAction(){ return attackActions; }
	inline int GetSpeed(){ return _moveSpeed; }
	inline void SetAttackStatus(AttackStatus attackStatus){ _attackStatus = attackStatus; }
	inline void SetHealth(int value){ health = value; }
	inline void SetImpossible(bool flag){ impossible = flag; }
	inline void SetGroup(CharacterGroup groupType){ _groupType = groupType; }
	inline void SetAttackAction(AttackAction* baseAttack){ attackActions.push_back(baseAttack); }
	inline void SetSpeed(int value){ _moveSpeed = value; }

	std::vector<AttackAction*> attackActions;
	// �ߋ��̈ʒu
	BaseSection* pastRoom;
	BaseCharacterState* pCharacterState;
	CharacterStateID stateID;
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
	int _moveSpeed;
};

