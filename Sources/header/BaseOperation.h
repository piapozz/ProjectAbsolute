#pragma once
#include "../header/Const.h"
#include <vector>
class OfficerPlayer;

/*
 * Sakakura
 * ��Ɗ��N���X
 */
class BaseOperation
{
public:
	BaseOperation()
		:_operatorParameter(-1), _operatorLevel(-1), _currentSpeed(-1), _currentProbability(-1), _frameCounter(0), _currentOperationCount(-1){}
	BaseOperation(int masterEntityID);
	virtual ~BaseOperation(){}

	/// <summary>
	/// ��Ə���
	/// </summary>
	/// <returns></returns>
	bool OperationProc();
	/// <summary>
	/// ��Ǝ҂�ID���Z�b�g
	/// </summary>
	/// <param name="_operatorID"></param>
	void SetOperator(OfficerPlayer* setOfficer);
	/// <summary>
	/// ���������擾
	/// </summary>
	/// <returns></returns>
	int GetSuccessCount();

protected:
	// ��Ɖ�
	int operateCount;
	// ��Ƃ̊�{�����m��
	float operateDefaultProbability[5];

private:
	// ��Ƃ̌���
	enum class Result
	{
		Invalid = -1,
		Success,
		Failure
	};

	// ��Ƃ̕W���t���[��
	const int _DEFAULT_OPERATE_FRAME = 180;
	const float _OPERATE_SPEED_RATIO = 0.01f;
	const float _OPERATE_PROBABILITY_RATIO = 0.2f;

	// ��Ə��
	std::vector<Result> _operationResultList;
	// ��Ǝ҂̍�ƃp�����[�^�[
	int _operatorParameter;
	// ��Ǝ҂̃��x��
	int _operatorLevel;
	// ���݂̑��x
	int _currentSpeed;
	// ���݂̐����m��
	float _currentProbability;
	// �t���[���J�E���^�[
	int _frameCounter;
	// ���݂̍�Ɖ�
	int _currentOperationCount;
};

