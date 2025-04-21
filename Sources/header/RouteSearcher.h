#pragma once
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
#include "CommonModule.h"
#include "Const.h"

// ノードクラス（A*用）
class Node 
{
public:
	int x, y;
	// スタートからのコスト
	int g = 999999;   
	// ゴールまでの推定コスト
	int h = 0;
	// 合計コスト f = g + h
	int f = 0;
	Node* parent = nullptr;

	Node(int x, int y): x(x), y(y) { }
};

// 優先度付きキュー用 比較関数
struct CompareNode
{
	bool operator()(const Node* a, const Node* b) const
	{
		return a->f > b->f;
	}
};

// 4方向の移動（上・下・左・右）
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
/*
* Ishihara
* 経路探索
*/
class RouteSearcher
{
public:
	/// <summary>
	/// 経路探索する
	/// </summary>
	/// <param name="stageData"></param>
	/// <param name="start"></param>
	/// <param name="goal"></param>
	/// <returns></returns>
	static std::vector<Vector2> RouteSearch(std::vector<std::vector<int>> stageData, Vector2 start, Vector2 goal);
};

