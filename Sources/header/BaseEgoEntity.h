#pragma once
#include "../header/BaseEntity.h"
class BaseOperation;

/*
 * Sakakura
 * 通常エンティティーの基底
 */
class BaseEgoEntity: public BaseEntity
{
public:
	// 作業結果
	enum class Feeling
	{
		Good = 0,
		Normal,
		Bad,
	};
	// 状態
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
	/// 作業を開始する
	/// </summary>
	/// <param name="operation"></param>
	/// <param name="operatorID"></param>
	void StartOperation(Type operation, int operatorID);
	inline bool IsTool() override { return false; }
	inline bool CanMeltdown() override { return _currentState != State::OPERATE; }

protected:
	// 現在のステート
	State _currentState;
	// 作業
	BaseOperation* _pOperation[(int)Type::MAX];
	// 現在の作業
	Type _currentOperationType;

	/// <summary>
	/// 作業開始時イベント
	/// </summary>
	virtual void StartOperationEvent(){}
	/// <summary>
	/// 作業終了時イベント
	/// </summary>
	/// <param name="successCount"></param>
	virtual void EndOperationEvent(int successCount){}

private:
	/// <summary>
	/// 作業の処理
	/// </summary>
	void OperationProc();
};

