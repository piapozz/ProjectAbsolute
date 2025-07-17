#pragma once
#include "../header/BaseOfficer.h"
#include "../header/OfficerPlayer.h"
#include "../header/OfficerMob.h"
#include "../header/ObjectManager.h"
#include "../header/StageManager.h"
#include <vector>

class OfficerInitData;

/*
 * Sein
 * Officer管理クラス
 */
class OfficerManager
{
public:
	OfficerManager();
	~OfficerManager();

	void Init();
	void Proc();
	void Teardown();

	static OfficerManager& Instance() {
		static OfficerManager instance;
		return instance;
	}

	BaseOfficer* AddOfficer(OfficerType type, OfficerInitData data, Vector2 position);
	void MoveSelectedPlayer(std::vector<int> officerNumber);
	vector<OfficerInitData> GetAliveOfficerData();
	/// <summary>
	/// 全職員が行動不可か否か
	/// </summary>
	/// <returns></returns>
	bool IsAllOfficerRestricted();
	std::vector<BaseOfficer*> GetOfficerList() { return _officerList; }
	inline void SetDisplayGameOverUI(std::function<void()> setCallback){ DisplayGameOverUI = setCallback; }

	std::function<void()> DisplayGameOverUI;

private:
	std::vector<BaseOfficer*> _officerList;

	const Vector2 DEFAULT_OFFICER_POSITION = {0, 0};
	const int DEFAULT_OFFICER_COUNT = 3;
};