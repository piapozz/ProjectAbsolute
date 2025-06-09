#pragma once
#include "Const.h"
#include "DxLib.h"
#include "functional"
/*
* Ishihara
* シーンの基底
*/
class BaseScene 
{
protected:
	// コールバック
	std::function<void(SceneName)> ChangeScene;
public:
	BaseScene(){}
	virtual ~BaseScene(){}

	/// <summary>
	/// シーン変更コールバック設定
	/// </summary>
	/// <param name="setCallback"></param>
	inline void SetCallback(const std::function<void(SceneName)>& setCallback){ ChangeScene = setCallback; }
	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init() = 0;
};
