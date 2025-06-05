#include "../header/CharacterStateFightMove.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"

CharacterStateFightMove::CharacterStateFightMove(std::vector<Vector2> targetPosList, BaseCharacter* targetCharacter)
{
	_routeList = targetPosList;
	_targetCharacter = targetCharacter;
}

void CharacterStateFightMove::Update(BaseCharacter* character)
{
	// �����ړI�n�ɓ��B���Ă����珈�����I��
	if (_arrayCount >= _routeList.size())
	{
		character->SetPosition(_routeList.back());
		character->ChangeState(CharacterStateID::IDLE);

		return;
	}

	Vector2 current = character->GetPosition();
	Vector2 target = _routeList[_arrayCount];

	// �܂�x�����̈ړ�������������
	float dx = target.x - current.x;
	float distance = std::abs(dx);

	if (distance < 2.0f)
	{
		current.x = target.x;
		character->SetPosition(current);
		_arrayCount++;

		return;
	}

	// x�ړ������炩�ɐi�߂�
	float moveX = (dx / distance) * speed;
	current.x += moveX;

	// �܂�y�ړ����Ȃ�
	current.y = target.y;

	character->SetPosition(current);
}

void CharacterStateFightMove::Enter(BaseCharacter* character)
{
	character->color = MOVE;
	_arrayCount = 0;
	character->stateID = CharacterStateID::FIGHT_MOVE;
}

void CharacterStateFightMove::Exit(BaseCharacter* character)
{
	character->color = IDLE;
	_routeList.clear();
}