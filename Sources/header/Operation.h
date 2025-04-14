#pragma once
#include "../header/Const.h"

/*
 * Sakakura
 * ���
 */
class Operation
{
public:
	Operation(int masterEntityID);
	~Operation(){}

private:
	// ��Ƃ̕W���t���[��
	const int _DEFAULT_OPERATE_FRAME = 180;
	const float _OPERATE_SPEED_RATIO = 0.01f;
	const float _OPERATE_PROBABILITY_RATIO = 0.002f;

	int _operateCount;
	// ���݂̍��
	OperationType _currentOperation;
	// ��Ƃ̑��x
	int _operateSpeed;
	// ��Ɛ����m��
	float _operateProbability;
};

