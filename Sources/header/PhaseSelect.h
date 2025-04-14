#pragma once
#include "BasePhase.h"

/*
 * Sakakura
 * 選択フェーズ
 */
class PhaseSelect : public BasePhase
{
public:
	PhaseSelect() { Init(); }
	~PhaseSelect() {};

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

