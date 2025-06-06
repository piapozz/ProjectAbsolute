#include "../header/SelectorNearOfficer.h"
#include "../header/BaseCharacter.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/ObjectManager.h"

std::vector<BaseCharacter*> SelectorNearOfficer::SelectTargets(BaseCharacter* attacker)
{
	BaseCharacter* nearOfficer = nullptr;
	Vector2 attackerPos = attacker->GetPosition();
	OfficerManager& officerManager = OfficerManager::Instance();
	std::vector<BaseOfficer*> officerList = officerManager.Instance().GetOfficerList();
	ObjectManager& objectManager = ObjectManager::Instance();

	int minDist = -1;

	for (int i = 0; i < officerList.size();i++)
	{
		BaseCharacter* chara = dynamic_cast<BaseCharacter*>(officerList[i]);
		if (!chara) continue;

		Vector2 pos = chara->GetPosition();
		int dx = pos.x - attackerPos.x;
		int dy = pos.y - attackerPos.y;
		int dist = dx * dx + dy * dy;

		if (minDist == -1 || dist < minDist)
		{
			minDist = dist;
			nearOfficer = chara;
		}
	}

	if (nearOfficer) return {nearOfficer};
	return {};
}