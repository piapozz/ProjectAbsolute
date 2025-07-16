#pragma once
#include <vector>
#include "PhaseSelect.h"
#include "PhaseStandby.h"
#include "PhaseMain.h"
#include "PhaseResult.h"

class EntityManager;
class ObjectManager;
/*
 * Sakakura
 * フェーズ管理クラス
 */
class PhaseManager
{
public:
	PhaseManager() {}
	~PhaseManager() {}

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// 破棄
	/// </summary>
	void Teardown();
	inline void SetCallback(const std::function<void(SceneName)>& setCallback){ _ChangeScene = setCallback; }

private:
	// フェーズ
	BasePhase* _currentPhase;
	int _currentDay;

	void ChangePhase(PhaseName nextPhase);
	std::function<void(SceneName)> _ChangeScene;
};

