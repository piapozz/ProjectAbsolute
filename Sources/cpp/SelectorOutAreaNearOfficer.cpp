#include "../header/SelectorOutAreaNearOfficer.h"
#include "../header/BaseCharacter.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/ObjectManager.h"

//std::vector<BaseCharacter*> NearestEnemySelector::SelectTargets(BaseCharacter* attacker) {
//	BaseCharacter* nearOfficer = nullptr;
//	int minDistSq = -1;
//
//	// ƒLƒƒƒ‰‚ð‘SˆõŽæ“¾
//	std::vector<BaseObject*> allCharacter = ObjectManager::instance->GetAllCharacter(ObjectType::CHARACTER);
//	Vector2 attackerPos = attacker->GetPosition();
//
//	for (int i = 0; i < allCharacter.size();i++)
//	{
//		BaseCharacter* chara = dynamic_cast<BaseCharacter*>(allCharacter[i]);
//		if (!chara || chara->GetGroup() == attacker->GetGroup()) continue;
//
//		Vector2 pos = chara->GetPosition();
//		int dx = pos.x - attackerPos.x;
//		int dy = pos.y - attackerPos.y;
//		int distSq = dx * dx + dy * dy;
//
//		if (minDistSq == -1 || distSq < minDistSq)
//		{
//			minDistSq = distSq;
//			nearOfficer = chara;
//		}
//	}
//
//	if (nearOfficer) return {nearOfficer};
//	return {};
//}

std::vector<BaseCharacter*> SelectorOutAreaNearOfficer::SelectTargets(BaseCharacter* attacker)
{
	BaseCharacter* nearOfficer;
	Vector2 attackerPos = attacker->GetPosition();
	OfficerManager& officerManager = OfficerManager::Instance();
	std::vector<BaseOfficer*> officerList = officerManager.Instance().GetOfficerList();
	ObjectManager& objectManager = ObjectManager::Instance();

	int routeMinCount = 100;

	for (int i = 0;i < officerList.size();i++)
	{
		Vector2 targetPos = officerList[i]->GetPosition();
		std::vector<Vector2> playerToRoute = StageManager::FindPath(attackerPos, targetPos);

		int routeCount = playerToRoute.size();

		if (routeMinCount > routeCount)
		{
			nearOfficer = officerList[i];
			routeMinCount = routeCount;
		}
	}

	std::vector<BaseCharacter*> index;
	index.push_back(nearOfficer);
	//if (!index) return nullptr;

	return index;
}

