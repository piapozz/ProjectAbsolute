#pragma once
#include "../header/BaseEntity.h"
#include "../header/OperationSatisfy.h"
#include "../header/OperationObserbation.h"
#include "../header/OperationContact.h"
#include "../header/OperationInjure.h"

/*
 * Sakakura
 * �ʏ�G���e�B�e�B�[�̊��
 */
class BaseEgoEntity: public BaseEntity
{
public:
	// ��ƌ���
	enum class Feeling
	{
		Good = 0,
		Normal,
		Bad,
	};
	// ���
	enum class State
	{
		NONE = -1,
		IDLE,
		OPERATE,
		RUNAWAY,
	};

	BaseEgoEntity(){ Init(); }
	virtual ~BaseEgoEntity(){}

	void Init();
	void Proc() override;

	/// <summary>
	/// ��Ƃ��J�n����
	/// </summary>
	/// <param name="operation"></param>
	/// <param name="operatorID"></param>
	void StartOperation(Type operation, int operatorID);
	/// <summary>
	/// ��Ƃ̏���
	/// </summary>
	void OperationProc();
	inline bool IsTool() override { return false; }
	inline bool CanMeltdown() override { return _currentState != State::OPERATE; }
	/// <summary>
	/// ��ƊJ�n���C�x���g
	/// </summary>
	virtual void StartOperationEvent(int operatorID){}
	/// <summary>
	/// ��ƏI�����C�x���g
	/// </summary>
	/// <param name="successCount"></param>
	virtual void EndOperationEvent(int successCount, int operatorID){}

protected:
	// ���݂̃X�e�[�g
	State _currentState;
	// ���
	BaseOperation* _pOperation[(int)Type::MAX];
	// ���݂̍��
	Type _currentOperationType;
};

