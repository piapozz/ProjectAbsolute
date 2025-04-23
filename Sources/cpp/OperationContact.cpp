#include "../header/OperationContact.h"

OperationContact::OperationContact(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI)
{
	// マスターデータから作業成功確率、作業回数を取得
	// 今はベタ打ち
	operateDefaultProbability[0] = 100.0f;
	operateDefaultProbability[1] = 100.0f;
	operateDefaultProbability[2] = 100.0f;
	operateDefaultProbability[3] = 100.0f;
	operateDefaultProbability[4] = 100.0f;
}