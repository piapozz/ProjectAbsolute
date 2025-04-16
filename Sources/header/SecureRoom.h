#pragma once
#include "../header/BaseSection.h"
#include "../header/BaseEntity.h"
#include "../header/BaseToolEntity.h"
#include "../header/OperationSatisfy.h"
#include "../header/OperationObserbation.h"
#include "../header/OperationContact.h"
#include "../header/OperationInjure.h"

/*
 * Sakakura
 * ���e��
 */
class SecureRoom: public BaseSection
{
public:
	SecureRoom(BaseEntity* pEntity)
		:_pEntity(pEntity), _isMeltdown(false), _meltdownCount(0){ Init(); }
	~SecureRoom(){ Teardown(); }

	void Init();
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	/// <summary>
	/// ��Ƃ��J�n����
	/// </summary>
	/// <param name="operation"></param>
	/// <param name="operatorID"></param>
	void StartOperation(Type operation, int operatorID);
	/// <summary>
	/// �����g�_�E���̊J�n
	/// </summary>
	void StartMeltdown();

private:
	// ���e���̏��
	enum class State
	{
		NONE = -1,
		IDLE,
		OPERATE,
		EMERGENCY,
		USE,
	};

	// �����g�_�E���̃J�E���g��
	int _MELTDOWN_COUNT = 60 * 60;
	// ���݂̃X�e�[�g
	State _currentState;
	// ���e���Ă���G���e�B�e�B�[
	BaseEntity* _pEntity;
	// ���
	BaseOperation* _pOperation[(int)Type::MAX];
	// ���݂̍��
	Type _currentOperationType;
	bool _isMeltdown;
	int _meltdownCount;

	/// <summary>
	/// ��Ƃ̏���
	/// </summary>
	void OperationProc();
	/// <summary>
	/// �����g�_�E���̃J�E���g������
	/// </summary>
	void CountMeltdown();
};

