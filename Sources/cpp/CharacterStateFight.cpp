#include "../header/CharacterStateFight.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/BaseAttack.h"

void CharacterStateFight::Update(BaseCharacter* character)
{
	if (!character->targetCharacter)
	{
		character->ChangeState(CharacterStateID::IDLE);
		return;
	}

	int nowCount = GetNowCount();

	// UŒ‚’†‚Ìˆ—
	if (isAttacking)
	{
		if (!hasAttacked && nowCount >= _attackHitTiming)
		{
			_attack->characterAttack->Attack(character, character->targetCharacter);
			hasAttacked = true;
		}

		if (nowCount >= _attackStartCount + _attackDuration) 
		{
			isAttacking = false;
			hasAttacked = false;
			_attackStartCount = nowCount + _coolTime;
		}
		return;
	}

	if (nowCount >= _attackStartCount) 
	{
		if (CheckRange(character)) 
		{
			StartAttack();
		}
	}
}

void CharacterStateFight::Enter(BaseCharacter* character)
{
	character->color = FIGHT;
	character->stateID = CharacterStateID::FIGHT;

	_attack = character->GetAttackAction()[0];

	isAttacking = false;
	hasAttacked = false;
	_attackStartCount = GetNowCount();
}

void CharacterStateFight::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}

bool CharacterStateFight::CheckRange(BaseCharacter* character)
{
	Vector2 attackerPos = character->GetTransform().position;
	Vector2 targetPos = character->targetCharacter->GetTransform().position;

	int dx = targetPos.x - attackerPos.x;
	return abs(dx) <= _attack->attackRange;
}

void CharacterStateFight::StartAttack()
{
	isAttacking = true;
	hasAttacked = false;
	_attackStartCount = GetNowCount();
	_attackHitTiming = _attackStartCount + _hitTimingOffset;
}
