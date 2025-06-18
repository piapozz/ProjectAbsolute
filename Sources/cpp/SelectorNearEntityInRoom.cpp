#include "../header/SelectorNearEntityInRoom.h"
#include "../header/BaseCharacter.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/ObjectManager.h"


std::vector<BaseCharacter*> SelectorNearEntityInRoom::SelectTargets(BaseCharacter* attacker)
{
	BaseCharacter* nearEntity = nullptr;
	ObjectManager& objectManager = ObjectManager::Instance();

	// “¯‚¶‹æ‰æ‚É“G‘Î‘ÎÛ‚ª‚¢‚é‚©ŒŸõ
	Vector2 attackerPos = attacker->GetTransform().position;
	BaseObject* attackerSection = objectManager.FindPosObject(attackerPos, ObjectType::SECTION);
	Vector2 sectionPosition = attackerSection->GetTransform().position;
	Vector2 sectionSize = attackerSection->GetTransform().scale;

	std::vector<BaseObject*> targetObjectList = objectManager.FindRectAllObject(sectionPosition, sectionSize, ObjectType::CHARACTER);
	std::vector<BaseCharacter*> targetList;

	for (int i = 0; i < targetObjectList.size();i++)
	{
		BaseCharacter* character = static_cast<BaseCharacter*>(targetObjectList[i]);
		if (character == attacker) return {};
		CharacterGroup group = character->GetGroup();
		if (group == CharacterGroup::OFFICER) targetList.push_back(character);
	}

	if (targetList.empty()) return{};

	int minDist = -1;

	for (int i = 0; i < targetList.size();i++)
	{	
		Vector2 pos = targetList[i]->GetTransform().position;
		int dx = pos.x - attackerPos.x;
		int dy = pos.y - attackerPos.y;
		int dist = dx * dx + dy * dy;

		if (minDist == -1 || dist < minDist)
		{
			minDist = dist;
			nearEntity = targetList[i];
		}
	}

	if (nearEntity) return {nearEntity};
	return {};
}