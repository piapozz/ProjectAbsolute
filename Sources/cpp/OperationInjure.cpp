#include "../header/OperationInjure.h"

OperationInjure::OperationInjure(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI)
{
	// マスターデータから作業成功確率、作業回数を取得
	// 今はベタ打ち
	operateDefaultProbability[0] = 40.0f;
	operateDefaultProbability[1] = 40.0f;
	operateDefaultProbability[2] = 40.0f;
	operateDefaultProbability[3] = 40.0f;
	operateDefaultProbability[4] = 40.0f;
}
