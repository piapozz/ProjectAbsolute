#include "../header/PhaseSelect.h"

void SelectEntity(int selectNum);

void PhaseSelect::Init()
{
	// 入力受付クラスを生成


	// 選択肢を初期化
	for (int i = 0; i < _MAX_SELECT_ENTITY; i++)
	{
		// エンティティーのプールから所持していないエンティティーを抜き出す
		// ランダムなエンティティーを追加する
		_selectEntityIDList[i] = -1;
	}

	// リストに応じたUIを生成

}

void PhaseSelect::SelectEntity(int selectNum)
{
	
}