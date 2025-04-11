#pragma once
#include <vector>
#include "FaseSelect.h"
#include "FaseStandby.h"
#include "FaseMain.h"
#include "FaseResult.h"

/*
 * Sakakura
 * フェーズ管理クラス
 */
class FaseManager
{
public:
	inline FaseManager() { Init(); }
	~FaseManager() { Teardown(); }

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
	std::vector<BaseFase*> _faseList;
};

