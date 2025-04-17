#include "../header/OfficerStateMove.h"
#include "../header/BaseOfficer.h"

OfficerStateMove::OfficerStateMove(std::vector<Vector2> targePostList)
{
	_routeList = targePostList;
}

void OfficerStateMove::Update(BaseOfficer* officer)
{
	if (_arrayCount >= _routeList.size()) 
	{
		officer->ChangeState(OfficerStateID::OFFICER_IDLE);
		return;
	}

	Vector2 target = _routeList[_arrayCount];
	Vector2 current = officer->GetPosition();

	Vector2 dir = target - current;
	float distance = sqrt(dir.x * dir.x + dir.y * dir.y);

	if (distance < 1.0f) 
	{
		_arrayCount++;
		return;
	}

	// ³‹K‰»
	Vector2 move = dir / distance;
	Vector2 indexVector = move * 3;
	current = indexVector + current;

	officer->SetPosition(current);
}

void OfficerStateMove::Enter(BaseOfficer* officer)
{
	officer->color = MOVE;
	_arrayCount = 0;
	_routeList.clear();
}

void OfficerStateMove::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
}