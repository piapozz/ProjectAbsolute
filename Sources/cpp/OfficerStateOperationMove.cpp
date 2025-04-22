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
	// �����ړI�n�ɓ��B���Ă����珈�����I��
	if (_arrayCount >= _routeList.size())
	{
		officer->SetPosition(_routeList.back());
		officer->ChangeState(OfficerStateID::OFFICER_IDLE);
		return;
	}

	Vector2 current = officer->GetPosition();
	Vector2 target = _routeList[_arrayCount];

	// �܂�x�����̈ړ�������������
	float dx = target.x - current.x;
	float distance = std::abs(dx);

	if (distance < 1.0f)
	{
		current.x = target.x;
		officer->SetPosition(current);
		_arrayCount++;

		return;
	}

	// x�ړ������炩�ɐi�߂�
	float moveX = (dx / distance) * speed;
	current.x += moveX;

	// �܂�y�ړ����Ȃ�
	current.y = target.y;

	officer->SetPosition(current);

	if (_arrayCount == _routeList.size())
	{
		officer->ChangeState(OfficerStateID::OFFICER_OPERATION);
	}
}

void OfficerStateOperationMove::Enter(BaseOfficer* officer)
{
	// ��Ƃ��s���ɍs���ʒm���o��
	officer->color = OPERATION_MOVE;
}

void OfficerStateOperationMove::Exit(BaseOfficer* officer)
{
	// ���e���ɓ��������ʒm���o��
	_secureRoom->StartOperation();
	_routeList.clear();
	officer->color = IDLE;

}