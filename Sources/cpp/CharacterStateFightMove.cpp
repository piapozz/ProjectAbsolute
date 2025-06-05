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
	// もし目的地に到達していたら処理を終了
	if (_arrayCount >= _routeList.size())
	{
		character->SetPosition(_routeList.back());
		character->ChangeState(CharacterStateID::IDLE);

		return;
	}

	Vector2 current = character->GetPosition();
	Vector2 target = _routeList[_arrayCount];

	// まずx方向の移動を完了させる
	float dx = target.x - current.x;
	float distance = std::abs(dx);

	if (distance < 2.0f)
	{
		current.x = target.x;
		character->SetPosition(current);
		_arrayCount++;

		return;
	}

	// x移動を滑らかに進める
	float moveX = (dx / distance) * speed;
	current.x += moveX;

	// まだy移動しない
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