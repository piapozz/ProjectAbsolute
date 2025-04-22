#include "../header/OperationInjure.h"

OperationInjure::OperationInjure(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI)
{
	// マスターデータから作業成功確率、作業回数を取得
	// 今はベタ打ち
	operateCount = 10;
	operateDefaultProbability[0] = 50.0f;
	operateDefaultProbability[1] = 30.0f;
	operateDefaultProbability[2] = 10.0f;
	operateDefaultProbability[3] = 5.0f;
	operateDefaultProbability[4] = 1.0f;
}
