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

bool PhaseSelect::Proc()
{
	// 入力受付

	// 終了
	return true;
}

void PhaseSelect::SelectEntity(int selectNum)
{
	
}

void PhaseSelect::InputProc()
{
	// 入力によって分岐
	// 選択されたら
	// エンティティーリストに追加
	SelectEntity(-1);
}