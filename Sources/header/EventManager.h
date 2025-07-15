#pragma once
#include "UIScreenSlider.h"
#include "UIScreenButton.h"
/*
* ishihara
* イベント管理
*/
class EventManager
{
public:
	static EventManager& Instance()
	{
		static EventManager instance;
		return instance;
	}

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
	inline bool IsMaxEnergy(){ return _energy >= _MAX_ENERGY; }
	inline int GetEnergy(){ return _energy; }
private:
	// エネルギー最大値
	const int _MAX_ENERGY = 100;
	// メルトダウン最大値
	const int _MELT_MAX = 3;
	// 暴走レベル最大値
	const int _MELT_LEVEL_MAX = 10;
	// エネルギー
	int _energy;
	// メルトダウンカウンター
	int _melt;
	// 暴走レベル
	int meltLevel;
	// 進捗スライダー
	UIScreenSlider* _pEnergySlider;
	// メルトダウンスライダー
	UIScreenSlider* _pMeltSlider;
	// 停止ボタン
	UIScreenButton* _pStopButton;
	// 通常再生ボタン
	UIScreenButton* _pNormalSpeedButton;
	// 倍速再生ボタン
	UIScreenButton* _pFastSpeedButton;
};