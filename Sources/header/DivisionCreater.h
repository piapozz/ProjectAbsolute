#pragma once
#include "Const.h"
#include "Division.h"

/*
アンカーに沿った区画の生成
区画番号の設定
リスポーン地点の設定
*/

class DivisionCreater
{
public:

	// シングルトンパターンのインスタンス取得
	static DivisionCreater& Instance() {
		static DivisionCreater instance;
		return instance;
	}

	// コンストラクタ
	DivisionCreater(){}
	// デストラクタ
	~DivisionCreater(){}

	/// <summary>
	/// 区画生成
	/// </summary>
	Division* CreateDivision(Vector2 anchor);
	/// <summary>
	/// 部屋がつながっているかどうか
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="type"></param>
	/// <returns></returns>
	int CheckSectionSize(int x, int y, SectionType type);

	// 区画プリセットの設定
	void SetDivisionPreset(std::vector<std::vector<int>> divisionPreset) {
		_divisionPreset = divisionPreset;
	}
	// 区画プリセットの取得
	std::vector<std::vector<int>> GetDivisionnPreset() const {
		return _divisionPreset;
	}
private:
	// 事前に初期化された訪問フラグ
	std::vector<std::vector<bool>> _visited;
	std::vector<std::vector<int>> _divisionPreset;
};

