#include "../header/OfficerStateOperationMove.h"
#include "../header/BaseOfficer.h"
#include "../header/SecureRoom.h"

OfficerStateOperationMove::OfficerStateOperationMove(std::vector<Vector2> targetPosList, SecureRoom* secureRoom)
{
	_routeList = targetPosList;
	_secureRoom = secureRoom;
	_arrayCount = 0;
}

void OfficerStateOperationMove::Update(BaseOfficer* officer)
{
	// もし目的地に到達していたら処理を終了
	if (_arrayCount >= _routeList.size())
	{
		officer->SetPosition(_routeList.back());
		officer->ChangeState(OfficerStateID::OFFICER_IDLE);
		return;
	}

	Vector2 current = officer->GetPosition();
	Vector2 target = _routeList[_arrayCount];

	// まずx方向の移動を完了させる
	float dx = target.x - current.x;
	float distance = std::abs(dx);

	if (distance < 1.0f)
	{
		current.x = target.x;
		officer->SetPosition(current);
		_arrayCount++;

		return;
	}

	// x移動を滑らかに進める
	float moveX = (dx / distance) * speed;
	current.x += moveX;

	// まだy移動しない
	current.y = target.y;

	officer->SetPosition(current);

	if (_arrayCount == _routeList.size())
	{
		officer->ChangeState(OfficerStateID::OFFICER_OPERATION);
	}
}

void OfficerStateOperationMove::Enter(BaseOfficer* officer)
{
	// 作業を行いに行く通知を出す
	officer->color = OPERATION_MOVE;
}

void OfficerStateOperationMove::Exit(BaseOfficer* officer)
{
	// 収容所に到着した通知を出す
	_secureRoom->StartOperation();
	_routeList.clear();
	officer->color = IDLE;

}