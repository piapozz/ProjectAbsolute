#include "../header/OfficerMob.h"
#include "../header/BaseCharacterState.h"
#include "../header/OfficerController.h"
#include "../header/SelectorFarEntityInRoom.h"
#include "../header/AttackBetweenCharacters.h"

void OfficerMob::Init(OfficerInitData data, int setOfficerID, Vector2 position)
{
	BaseOfficer::Init(data, setOfficerID,position);
	_groupType = CharacterGroup::OFFICER;
	SetImpossible(false);
	_officerType = OfficerType::MOB;
	layer = Layer::MIDDLE;
	pController = new OfficerController(this);

	AttackAction* normalAttack = new AttackAction();
	normalAttack->targetSelector = new SelectorFarEntityInRoom();
	normalAttack->characterAttack = new AttackBetweenCharacters();
	normalAttack->attackRange = 500;

	attackActions.push_back(normalAttack);
}

void OfficerMob::Proc()
{
	BaseOfficer::Proc();
	pController->UpdateAI();
}

void OfficerMob::Draw()
{
	BaseOfficer::Draw();
}

void OfficerMob::Teardown()
{
	BaseOfficer::Teardown();
}