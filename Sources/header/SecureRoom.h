#pragma once
#include "../header/BaseSection.h"
#include "../header/BaseEntity.h"
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
		:_pEntity(pEntity){ Init(); }
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

private:
	// ���e���̏��
	enum class State
	{
		NONE,
		IDLE,
		OPERATE,
		EMERGENCY,
	};

	// ���݂̃X�e�[�g
	State _currentState;
	// ���e���Ă���G���e�B�e�B�[
	BaseEntity* _pEntity;
	// ���
	BaseOperation* _pOperation[(int)Type::MAX];
	// ���݂̍��
	Type _currentOperationType;

	/// <summary>
	/// ��Ƃ̏���
	/// </summary>
	void OperationProc();
};

