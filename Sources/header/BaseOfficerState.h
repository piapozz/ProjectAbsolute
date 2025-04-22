#pragma once
#include <DxLib.h>
#include <vector>
#include "../header/CommonModule.h"
#include "../header/Const.h"

// 前方宣言
class BaseOfficer;

/*
 * Sein
 * OfficerのStateの基底クラス
 */
class BaseOfficerState
{
public:
	virtual void Update(BaseOfficer* officer){};
	virtual void Enter(BaseOfficer* officer){};
	virtual void Exit(BaseOfficer* officer){};

	unsigned int NONE = GetColor(0, 255, 255);		
	unsigned int IDLE = GetColor(255, 255, 255);	// 白
	unsigned int MOVE = GetColor(0, 255, 0);		// 緑
	unsigned int FIGHT = GetColor(255, 150, 0);		// オレンジ
	unsigned int OPERATION = GetColor(0, 0, 255);		// 青
	unsigned int OPERATION_MOVE = GetColor(100, 100, 255);		// 青
	unsigned int PANIC = GetColor(255, 0, 255);		// 紫
	unsigned int DEAD = GetColor(255, 0, 0);		// 赤
};