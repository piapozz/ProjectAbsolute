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
	inline bool IsMaxEnergy(){ return _energy >= _maxEnergy; }
	inline int GetEnergy(){ return _energy; }
	inline void SetResultCallback(std::function<void()> setCallback){ _DisplayContinueResult = setCallback; }
	inline void SetGetDayCallback(std::function<int()> setCallback){ _GetDay = setCallback; }

private:
	// エネルギー増加値
	const int _ADD_ENERGY = 15;
	// 1日ごとに増えていく係数
	const float _FACTOR_ENERGY = 1.05f;
	// メルトダウン最大値
	const int _MELT_MAX = 3;
	// 暴走レベル最大値
	const int _MELT_LEVEL_MAX = 10;
	// エネルギー
	int _energy;
	// エネルギー最大数
	int _maxEnergy;
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
	// ゲームオーバーコールバック
	std::function<void()> _DisplayContinueResult;
	// 日付取得コールバック
	std::function<int()> _GetDay;
};