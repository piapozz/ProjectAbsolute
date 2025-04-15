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
	inline PhaseManager() { Init(); }
	~PhaseManager() { Teardown(); }

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
	// オブジェクト管理クラス
	ObjectManager* _objectManager;
};

