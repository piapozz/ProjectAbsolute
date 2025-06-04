#include "../header/SelectorNearOfficer.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"

std::vector<BaseCharacter*> NearestEnemySelector::SelectTargets(BaseCharacter* attacker) {
	BaseCharacter* nearOfficer = nullptr;
	int minDistSq = -1;

	// ƒLƒƒƒ‰‚ð‘SˆõŽæ“¾
	std::vector<BaseObject*> allCharacter = ObjectManager::instance->GetAllCharacter(ObjectType::CHARACTER);
	Vector2 attackerPos = attacker->GetPosition();

	for (int i = 0; i < allCharacter.size();i++)
	{
		BaseCharacter* chara = dynamic_cast<BaseCharacter*>(allCharacter[i]);
		if (!chara || chara->GetGroup() == attacker->GetGroup()) continue;

		Vector2 pos = chara->GetPosition();
		int dx = pos.x - attackerPos.x;
		int dy = pos.y - attackerPos.y;
		int distSq = dx * dx + dy * dy;

		if (minDistSq == -1 || distSq < minDistSq)
		{
			minDistSq = distSq;
			nearOfficer = chara;
		}
	}

	if (nearOfficer) return {nearOfficer};
	return {};
}

