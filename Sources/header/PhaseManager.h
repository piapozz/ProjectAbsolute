#pragma once
#include <vector>
#include "PhaseSelect.h"
#include "PhaseStandby.h"
#include "PhaseMain.h"
#include "PhaseResult.h"
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

private:
	// フェーズ
	BasePhase* _currentPhase;

	inline void ChangePhase(PhaseName nextPhase);
};

