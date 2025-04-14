#pragma once
#include "../header/Const.h"

/*
 * Sakakura
 * 作業
 */
class Operation
{
public:
	Operation(int masterEntityID);
	~Operation(){}

private:
	// 作業の標準フレーム
	const int _DEFAULT_OPERATE_FRAME = 180;
	const float _OPERATE_SPEED_RATIO = 0.01f;
	const float _OPERATE_PROBABILITY_RATIO = 0.002f;

	int _operateCount;
	// 現在の作業
	OperationType _currentOperation;
	// 作業の速度
	int _operateSpeed;
	// 作業成功確率
	float _operateProbability;
};

