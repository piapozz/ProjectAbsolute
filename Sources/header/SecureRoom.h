#pragma once
#include "../header/BaseSection.h"
#include "../header/BaseEntity.h"
#include "../header/OperationSatisfy.h"
#include "../header/OperationObserbation.h"
#include "../header/OperationContact.h"
#include "../header/OperationInjure.h"

/*
 * Sakakura
 * 収容室
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
	/// 作業を開始する
	/// </summary>
	/// <param name="operation"></param>
	/// <param name="operatorID"></param>
	void StartOperation(Type operation, int operatorID);

private:
	// 収容室の状態
	enum class State
	{
		NONE,
		IDLE,
		OPERATE,
		EMERGENCY,
	};

	// 現在のステート
	State _currentState;
	// 収容しているエンティティー
	BaseEntity* _pEntity;
	// 作業
	BaseOperation* _pOperation[(int)Type::MAX];
	// 現在の作業
	Type _currentOperationType;

	/// <summary>
	/// 作業の処理
	/// </summary>
	void OperationProc();
};

