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
	inline PhaseManager() {}
	~PhaseManager() {}

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// 処理
	/// </summary>
	void Proc();
	/// <summary>
	/// 破棄
	/// </summary>
	void Teardown();

private:
	// フェーズのリスト
	std::vector<BasePhase*> _phaseList;
};

