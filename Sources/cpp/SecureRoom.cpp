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
			CountMeltdown();
			break;
		case State::OPERATE:
			// 作業の種類に応じた処理
			OperationProc();
			break;
		case State::EMERGENCY:
			break;
		case State::USE:
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
	// ツール型なら返す
	BaseToolEntity* pToolEntity = dynamic_cast<BaseToolEntity*>(_pEntity);
	if (pToolEntity != nullptr) return;

	// 待機状態でないなら返す
	if (_currentState != State::IDLE) return;

	_currentState = State::OPERATE;
	_currentOperationType = operation;
	_pOperation[(int)_currentOperationType]->SetOperator(operatorID);
	// エンティティの作業開始イベントを発生させる
	_pEntity->StartOperationEvent();
}

void SecureRoom::StartMeltdown()
{
	_isMeltdown = true;
	_meltdownCount = _MELTDOWN_COUNT;
}

void SecureRoom::OperationProc()
{
	// 作業の進行、作業が終了してないなら返す
	if (!_pOperation[(int)_currentState]->OperationProc()) return;

	// 作業が終了したら作業の結果を取得
	int successCount = _pOperation[(int)_currentState]->GetSuccessCount();
	// エンティティの作業終了イベントを発生させる
	_pEntity->EndOperationEvent(successCount);
	// 作業員のパラメーターを増加させる
	
}

void SecureRoom::CountMeltdown()
{
	if (!_isMeltdown) return;

	// メルトダウンカウントを減少させる
	_meltdownCount--;
	if (_meltdownCount > 0) return;

	// メルトダウンカウントが0になったら、エンティティーを暴走させる
	_pEntity->SetRunawayCount(0);
	_pEntity->RunawayEvent();
}