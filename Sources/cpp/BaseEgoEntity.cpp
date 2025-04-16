#include "../header/BaseEgoEntity.h"
#include "../header/OperationSatisfy.h"
#include "../header/OperationObserbation.h"
#include "../header/OperationContact.h"
#include "../header/OperationInjure.h"

void BaseEgoEntity::Init()
{
	// エンティティーのマスターデータから作業IDを取得し生成
	// _pOperation = new Operation(_pEntity->GetID());
	int entityID = 0;
	_pOperation[0] = new OperationSatisfy(entityID);
	_pOperation[1] = new OperationObserbation(entityID);
	_pOperation[2] = new OperationContact(entityID);
	_pOperation[3] = new OperationInjure(entityID);
}

void BaseEgoEntity::Proc()
{
	// エンティティーの状態に応じた処理
	switch (_currentState)
	{
		case State::NONE:
		case State::IDLE:
			break;
		case State::OPERATE:
			OperationProc();
			break;
		case State::RUNAWAY:
			break;
		default:
			break;
	}
}

void BaseEgoEntity::OperationProc()
{
	// 作業の進行、作業が終了してないなら返す
	if (!_pOperation[(int)_currentOperationType]->OperationProc()) return;
	// 作業が終了したら作業の結果を取得
	int successCount = _pOperation[(int)_currentOperationType]->GetSuccessCount();
	// エンティティの作業終了イベントを発生させる
	EndOperationEvent(successCount);
	// ステートを変更
	_currentState = State::IDLE;
	interactOfficerID = -1;
}

void BaseEgoEntity::StartOperation(Type operation, int operatorID)
{
	// 待機状態でないなら返す
	if (_currentState != State::IDLE) return;

	_currentState = State::OPERATE;
	_currentOperationType = operation;
	interactOfficerID = operatorID;
	_pOperation[(int)_currentOperationType]->SetOperator(operatorID);
	// 作業開始イベントを発生させる
	StartOperationEvent();
}