#pragma once
#include "UIScreenSlider.h"
/*
* ishihara
* イベント管理
*/
class EventManager
{
public:
	void Init();
	/// <summary>
	/// エネルギーの追加
	/// </summary>
	/// <param name="value"></param>
	void AddEnergy(int value);
	/// <summary>
	/// メルトカウンターの追加
	/// </summary>
	void AddMelt();
private:
	// エネルギー最大値
	const int _MAX_ENERGY = 100;
	// メルトダウン最大値
	const int _MELT_MAX = 2;
	// 暴走レベル
	const int _MELT_LEVEL_MAX = 10;
	// エネルギー
	int _energy;
	// メルトダウンカウンター
	int _melt;
	// 暴走レベル
	int meltLevel;
	// スライダー
	UIScreenSlider* _pEnergySlider;
};

