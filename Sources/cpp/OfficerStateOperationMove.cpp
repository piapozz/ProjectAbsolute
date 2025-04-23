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
	Vector2 current = officer->GetPosition();
	Vector2 target = _routeList[_arrayCount];
	int i = _routeList.size();

	// x�����̈ړ�
	float dx = target.x - current.x;
	float distance = std::abs(dx);

	float moveX = (dx / distance) * speed;
	current.x += moveX;
	current.y = target.y;

	officer->SetPosition(current);

	if (distance < 1.0f)
	{
		current.x = target.x;
		officer->SetPosition(current);
		_arrayCount++;
	}

	// ���ׂẴ��[�g�ɓ��B������X�e�[�g�J��
	if (_arrayCount == _routeList.size())
	{
		StateArgs* args = new StateArgs();
		args->secureRoom = _secureRoom;
		officer->ChangeState(OfficerStateID::OFFICER_OPERATION, args);
	}
}

void OfficerStateOperationMove::Enter(BaseOfficer* officer)
{
	// ��Ƃ��s���ɍs���ʒm���o��
	officer->color = OPERATION_MOVE;
}

void OfficerStateOperationMove::Exit(BaseOfficer* officer)
{
	_routeList.clear();
	officer->color = IDLE;

}