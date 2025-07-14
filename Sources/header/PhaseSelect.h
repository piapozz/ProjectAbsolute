#pragma once
#include "BasePhase.h"

/*
 * Sakakura
 * 選択フェーズ
 */
class PhaseSelect : public BasePhase
{
public:
	PhaseSelect() {}
	~PhaseSelect() {};

	void Init() override;
	void Teardown() override {};

protected:
	void OnCursorProc(Vector2 pos) override;
	void LReleaseInputProc(Vector2 pos, Vector2 oldPos) override;

private:
	// 選択できるエンティティーの最大数
	static const int _MAX_SELECT_ENTITY = 3;
	// 選択されるエンティーティーのIDリスト
	int _selectEntityIDList[_MAX_SELECT_ENTITY];
	const Vector2 _SELECT_ENTITY_POS[_MAX_SELECT_ENTITY] =
	{
		Vector2(-0.6f, 0),
		Vector2(0, 0),
		Vector2(0.6f, 0)
	};
	const Vector2 _SELECT_ENTITY_SCALE = Vector2(0.25f, 0.3f);

	/// <summary>
	/// エンティティーを選択する
	/// </summary>
	/// <param name="selectNum"></param>
	void SelectEntity(int selectNum);
};

