#include "../header/SecureRoom.h"

void SecureRoom::Init()
{
	// _pOperation = new Operation(_pEntity->GetID());
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
	// 描画
	BaseSection::Draw();
}

void SecureRoom::Teardown()
{
	// 破棄
	BaseSection::Teardown();
}

void SecureRoom::SetState(State setState)
{
	// ステートを切り替える
	_currentState = setState;
}

void SecureRoom::OperationProc()
{
	// 作業速度に応じて作業を進める
	
}