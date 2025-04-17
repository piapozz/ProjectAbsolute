#pragma once
#include "../header/BaseOfficer.h"
#include "../header/OfficerPlayer.h"
#include "../header/OfficerMob.h"
#include "../header/ObjectManager.h"
#include <vector>

/*
 * Sein
 * Officerä«óùÉNÉâÉX
 */
class OfficerManager
{
public:
	OfficerManager();
	~OfficerManager();

	void Init();
	void Proc();
	void Teardown();

	void AddOfficer(OfficerType type);

	std::vector<BaseOfficer*> GetOfficerList() { return _officerList; }

private:
	std::vector<BaseOfficer*> _officerList;

	const Vector2 DEFAULT_OFFICER_POSITION = {0, 0};
	const int DEFAULT_OFFICER_COUNT = 3;

};