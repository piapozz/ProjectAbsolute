#include "../header/BaseOperation.h"
#include "../header/OfficerPlayer.h"
#include "../header/UIButton.h"

BaseOperation::BaseOperation(int masterEntityID, UIButton* setUI)
{
	// 作業状態の初期化
	_operationResultList = std::vector<Result>(operateCount, Result::INVALID);
	_pOperationUI = setUI;
}

bool BaseOperation::OperationProc()
{
	// 作業の進行
	_frameCounter++;
	// 作業するフレームになったら処理
	if (_currentSpeed >= _frameCounter) return false;
	_currentOperationCount++;
	// 作業の成功をランダムに決める
	bool result = _currentProbability * 10 <= GetRand(1000);
	if (result)
	{
		// 失敗
		// ダメージを与える

		// 失敗を記録
		_operationResultList[_currentOperationCount - 1] = Result::FAILURE;
	}
	else
	{
		// 成功
		_operationResultList[_currentOperationCount - 1] = Result::SUCCESS;
	}

	// UIを更新
	std::string str = std::to_string(_currentOperationCount);
	_pOperationUI->SetButtonText(str);

	_frameCounter = 0;
	// 終了を確認
	if (_currentOperationCount < operateCount) return false;

	return true;
}

void BaseOperation::SetOperator(OfficerPlayer* setOfficer)
{
	// 作業者のIDからレベルとパラメーターを取得
	// 今はベタ打ち
	_operatorLevel = 1;
	_operatorParameter = 30;
	_currentSpeed = _DEFAULT_OPERATE_FRAME - (int)(_DEFAULT_OPERATE_FRAME / 2 * _OPERATE_SPEED_RATIO * _operatorParameter);
	_currentProbability = operateDefaultProbability[_operatorLevel - 1] + _OPERATE_PROBABILITY_RATIO * _operatorParameter;
	_frameCounter = 0;
	_currentOperationCount = 0;
	// 作業状態の初期化
	operateCount = 10;
	_operationResultList = std::vector<Result>(10, Result::INVALID);
}

int BaseOperation::GetSuccessCount()
{
	// 作業の結果を取得
	int result = 0;
	for (int i = 0; i < operateCount; i++)
	{
		if (_operationResultList[i] == Result::SUCCESS) result++;
	}
	return result;
}