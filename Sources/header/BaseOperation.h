#pragma once
#include "../header/Const.h"
#include <vector>
class OfficerPlayer;
class UIButton;

/*
 * Sakakura
 * 作業基底クラス
 */
class BaseOperation
{
public:
	BaseOperation()
		:_operatorParameter(-1), _operatorLevel(-1), _currentSpeed(-1), _currentProbability(-1), _frameCounter(0), _currentOperationCount(-1){}
	BaseOperation(int masterEntityID, UIButton* setUI);
	virtual ~BaseOperation(){}

	/// <summary>
	/// 作業処理
	/// </summary>
	/// <returns></returns>
	bool OperationProc();
	/// <summary>
	/// 作業者のIDをセット
	/// </summary>
	/// <param name="_operatorID"></param>
	void SetOperator(OfficerPlayer* setOfficer);
	/// <summary>
	/// 成功数を取得
	/// </summary>
	/// <returns></returns>
	int GetSuccessCount();

protected:
	// 作業回数
	int operateCount;
	// 作業の基本成功確率
	float operateDefaultProbability[5];

private:
	// 作業の結果
	enum class Result
	{
		INVALID = -1,
		SUCCESS,
		FAILURE
	};

	// 作業の標準フレーム
	const int _DEFAULT_OPERATE_FRAME = 180;
	const float _OPERATE_SPEED_RATIO = 0.01f;
	const float _OPERATE_PROBABILITY_RATIO = 0.2f;

	// 作業状態
	std::vector<Result> _operationResultList;
	// 作業者の作業パラメーター
	int _operatorParameter;
	// 作業者のレベル
	int _operatorLevel;
	// 現在の速度
	int _currentSpeed;
	// 現在の成功確率
	float _currentProbability;
	// フレームカウンター
	int _frameCounter;
	// 現在の作業回数
	int _currentOperationCount;
	UIButton* _pOperationUI;
};

