#pragma once
#include "BaseObject.h"
#include "../header/RouteSearcher.h"
#include "../header/StateArgs.h"

class BaseCharacterState;

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
	void ChangeState(OfficerStateID stateID, StateArgs* args = nullptr);
	void ChangeMoveState(Vector2 targetPos, SecureRoom* secureRoom = nullptr);
	bool CharacterMove(std::vector<Vector2> targetPosList, float speed);

	void SetPosition(Vector2 setPosition){ position = setPosition; }
	Vector2 GetPosition(){ return position; }
	Vector2 GetPastPosition(){ return _pastPosition; }
	int GetHealth(){ return health; }
	void SetHealth(int value){ health = value; }
	void SetImpossible(bool flag) { impossible = flag; }
	bool GetImpossible(){ return impossible; }

	// �ߋ��̈ʒu
	Vector2 _pastPosition;
	BaseCharacterState* pCharacterState;
	unsigned int color;

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
	// �X�e�[�g��J�ڂł��邩
	bool impossible;

private:
	int _moveListIndex;

};

