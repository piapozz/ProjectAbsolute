#include "../header/SecureRoom.h"

void SecureRoom::Init()
{
	// エンティティーのマスターデータから作業IDを取得し生成
	// _pOperation = new Operation(_pEntity->GetID());
	int entityID = 0;
	_pOperation[0] = new OperationSatisfy(entityID);
	_pOperation[1] = new OperationObserbation(entityID);
	_pOperation[2] = new OperationContact(entityID);
	_pOperation[3] = new OperationInjure(entityID);
}

void SecureRoom::Proc()
{
	// 収容室の状態に応じた処理
	switch (_currentState)
	{
		case State::NONE:
		case State::IDLE:
			break;
		case State::OPERATE:
			// 作業の種類に応じた処理
			OperationProc();
			break;
		case State::EMERGENCY:
			break;
		default:
			break;
	}
}

void SecureRoom::Draw()
{

}

void SecureRoom::Teardown()
{

}

void SecureRoom::StartOperation(Type operation, int operatorID)
{
	_currentState = State::OPERATE;
	_currentOperationType = operation;
	_pOperation[(int)_currentState]->SetOperator(operatorID);
}

void SecureRoom::OperationProc()
{
	// 作業速度に応じて作業を進める
	if (!_pOperation[(int)_currentState]->OperationProc()) return;

	// 作業が終了したら作業の結果を取得
	int successCount = _pOperation[(int)_currentState]->GetSuccessCount();
	// 作業員のパラメーターを増加させる
	
	// 作業の結果をエンティティーに通知

}