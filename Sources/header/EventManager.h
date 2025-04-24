#pragma once
#include "UISlider.h"
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
	// エネルギー
	int _energy;
	// メルトダウン最大値
	const int _MELT_MAX = 2;
	// メルトダウンカウンター
	int _melt;
	// スライダー
	UISlider* _pEnergySlider;
};

