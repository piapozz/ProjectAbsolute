#pragma once
#include "../header/BaseEntity.h"
class BaseOperation;

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

	BaseEgoEntity(){}
	virtual ~BaseEgoEntity(){}

	void Init();
	void Proc() override;
	/// <summary>
	/// ��Ƃ��J�n����
	/// </summary>
	/// <param name="operation"></param>
	/// <param name="operatorID"></param>
	void StartOperation(Type operation, int operatorID);
	inline bool IsTool() override { return false; }
	inline bool CanMeltdown() override { return _currentState != State::OPERATE; }

protected:
	// ���݂̃X�e�[�g
	State _currentState;
	// ���
	BaseOperation* _pOperation[(int)Type::MAX];
	// ���݂̍��
	Type _currentOperationType;

	/// <summary>
	/// ��ƊJ�n���C�x���g
	/// </summary>
	virtual void StartOperationEvent(){}
	/// <summary>
	/// ��ƏI�����C�x���g
	/// </summary>
	/// <param name="successCount"></param>
	virtual void EndOperationEvent(int successCount){}

private:
	/// <summary>
	/// ��Ƃ̏���
	/// </summary>
	void OperationProc();
};

