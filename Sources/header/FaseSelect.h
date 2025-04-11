#pragma once
#include "BaseFase.h"

/*
 * Sakakura
 * 選択フェーズ
 */
class FaseSelect : public BaseFase
{
public:
	FaseSelect() { Init(); }
	~FaseSelect() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void InputProc() override;

private:
	// 選択できるエンティティーの最大数
	static const int _MAX_SELECT_ENTITY = 3;
	// 選択される円ティーティーのIDリスト
	int _selectEntityIDList[_MAX_SELECT_ENTITY];

	/// <summary>
	/// エンティティーを選択する
	/// </summary>
	/// <param name="selectNum"></param>
	void SelectEntity(int selectNum);
};

