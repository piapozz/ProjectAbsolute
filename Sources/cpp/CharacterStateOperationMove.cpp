#include "../header/CharacterStateOperationMove.h"
#include "../header/BaseCharacter.h"
#include "../header/SecureRoom.h"

CharacterStateOperationMove::CharacterStateOperationMove(std::vector<Vector2> targetPosList, SecureRoom* secureRoom)
{
	_routeList = targetPosList;
	_secureRoom = secureRoom;
}

void CharacterStateOperationMove::Update(BaseCharacter* character)
{

	bool finishMove = false;
	finishMove = character->CharacterMove(_routeList, speed);
	if (finishMove)
	{
		StateArgs* args = new StateArgs();
		args->secureRoom = _secureRoom;
		character->ChangeState(OfficerStateID::OFFICER_OPERATION, args);
	}

	//Vector2 current = officer->GetPosition();
	//Vector2 target = _routeList[_arrayCount];
	//int i = _routeList.size();

	//// x�����̈ړ�
	//float dx = target.x - current.x;
	//float distance = std::abs(dx);

	//float moveX = (dx / distance) * speed;
	//current.x += moveX;
	//current.y = target.y;

	//officer->SetPosition(current);

	//if (distance < 1.0f)
	//{
	//	current.x = target.x;
	//	officer->SetPosition(current);
	//	_arrayCount++;
	//}

	//// ���ׂẴ��[�g�ɓ��B������X�e�[�g�J��
	//if (_arrayCount == _routeList.size())
	//{
	//	StateArgs* args = new StateArgs();
	//	args->secureRoom = _secureRoom;
	//	officer->ChangeState(OfficerStateID::OFFICER_OPERATION, args);
	//}
}

void CharacterStateOperationMove::Enter(BaseCharacter* character)
{
	// ��Ƃ��s���ɍs���ʒm���o��
	character->color = OPERATION_MOVE;
}

void CharacterStateOperationMove::Exit(BaseCharacter* character)
{
	_routeList.clear();
	character->color = IDLE;

}