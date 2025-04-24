#include "../header/CharacterStatePanic.h"
#include "../header/BaseCharacter.h"

void CharacterStatePanic::Update(BaseCharacter* character)
{
	std::vector<Vector2> routeList;
	routeList.push_back({0, 0});
	routeList.push_back({100, 100});
	routeList.push_back({-100, -100});
	routeList.push_back({-100, 100});
	StateArgs* args = new StateArgs();
	args->targetPosList = routeList;
	character->ChangeState(OfficerStateID::OFFICER_MOVE, args);
}

void CharacterStatePanic::Enter(BaseCharacter* character)
{
	character->color = PANIC;
}

void CharacterStatePanic::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}