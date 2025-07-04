#include "../header/SelectorFarOfficerInRoom.h"
#include "../header/BaseCharacter.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/ObjectManager.h"

std::vector<BaseCharacter*> SelectorFarOfficerInRoom::SelectTargets(BaseCharacter* attacker)
{
	BaseCharacter* farOfficer = nullptr;
	ObjectManager& objectManager = ObjectManager::Instance();

	Vector2 attackerPos = attacker->GetTransform().position;
	BaseObject* attackerSection = objectManager.FindPosObject(attackerPos, ObjectType::SECTION);
	Vector2 sectionPosition = attackerSection->GetTransform().position;
	Vector2 sectionSize = attackerSection->GetTransform().scale;

	std::vector<BaseObject*> targetObjectList = objectManager.FindRectAllObject(sectionPosition, sectionSize, ObjectType::CHARACTER);
	std::vector<BaseCharacter*> targetList;

	for (int i = 0; i < targetObjectList.size(); i++)
	{
		BaseCharacter* character = static_cast<BaseCharacter*>(targetObjectList[i]);
		if (character == attacker) continue;
		if (character->GetIsDead()) continue;

		CharacterGroup group = character->GetGroup();
		if (group == CharacterGroup::OFFICER)
		{
			targetList.push_back(character);
		}
	}

	if (targetList.empty()) return {};

	int maxDist = -1;

	for (int i = 0; i < targetList.size(); i++)
	{
		Vector2 pos = targetList[i]->GetTransform().position;
		int dx = pos.x - attackerPos.x;
		int dy = pos.y - attackerPos.y;
		int dist = dx * dx + dy * dy;

		if (dist > maxDist)
		{
			maxDist = dist;
			farOfficer = targetList[i];
		}
	}

	if (farOfficer) return {farOfficer};
	return {};
}
