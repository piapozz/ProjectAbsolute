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