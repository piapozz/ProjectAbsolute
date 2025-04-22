#include "../header/OfficerStateMove.h"
#include "../header/BaseOfficer.h"

OfficerStateMove::OfficerStateMove(std::vector<Vector2> targePostList)
{
	_routeList = targePostList;
}

void OfficerStateMove::Update(BaseOfficer* officer)
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
}

void OfficerStateMove::Enter(BaseOfficer* officer)
{
	officer->color = MOVE;
	_arrayCount = 0;
}

void OfficerStateMove::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
	_routeList.clear();
}