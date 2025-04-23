#include "../header/OperationSatisfy.h"

OperationSatisfy::OperationSatisfy(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI)
{
	// マスターデータから作業成功確率、作業回数を取得
	// 今はベタ打ち
	operateDefaultProbability[0] = 65.0f;
	operateDefaultProbability[1] = 65.0f;
	operateDefaultProbability[2] = 65.0f;
	operateDefaultProbability[3] = 65.0f;
	operateDefaultProbability[4] = 65.0f;
}