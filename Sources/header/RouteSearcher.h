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
	static std::vector<Vector2> RouteSearch(std::vector<std::vector<int>> stageData, Vector2 start, Vector2 goal) {
		int startX = (int)(start.x / SECTION_SIZE);
		int startY = (int)(-start.y / SECTION_SIZE);
		int goalX = (int)(goal.x / SECTION_SIZE);
		int goalY = (int)(-goal.y / SECTION_SIZE);

		if (startX < 0 || startX > STAGE_SIZE || startY < 0 || startY > STAGE_SIZE ||
			goalX < 0 || goalX > STAGE_SIZE || goalY < 0 || goalY > STAGE_SIZE) {
			// 範囲外の場合は空のベクターを返す
			return std::vector<Vector2>();
		}
		// ステージデータが空の場合は空のベクターを返す
		if (stageData.empty()) return std::vector<Vector2>(); 

		std::vector<std::vector<Node*>> nodes(STAGE_SIZE, std::vector<Node*>(STAGE_SIZE, nullptr));
		std::priority_queue<Node*, std::vector<Node*>, CompareNode> openSet;
		std::vector<Vector2> path;

		Node* startNode = new Node(startX, startY);
		startNode->g = 0;
		startNode->h = (std::abs(goalX - startX) + std::abs(goalY - startY)) * 10;
		startNode->f = startNode->g + startNode->h;
		openSet.push(startNode);
		nodes[startY][startX] = startNode;

		while (!openSet.empty()) {
			Node* current = openSet.top();
			openSet.pop();

			if (current->x == goalX && current->y == goalY) {
				while (current != nullptr) {
					path.push_back(Vector2(current->x * SECTION_SIZE, (-current->y * SECTION_SIZE) - (SECTION_SIZE / 2)));
					current = current->parent;
				}
				break;
			}

			for (int i = 0; i < 4; ++i) {
				int nx = current->x + dx[i];
				int ny = current->y + dy[i];

				if (nx < 0 || nx >= STAGE_SIZE || ny < 0 || ny >= STAGE_SIZE)
					continue;

				int tile = stageData[ny][nx];
				if (tile == 0) continue; // 通れないタイル

				if (nodes[ny][nx] == nullptr) {
					nodes[ny][nx] = new Node(nx, ny);
				}

				Node* neighbor = nodes[ny][nx];
				int cost = current->g + 10;

				if (cost < neighbor->g) {
					neighbor->g = cost;
					neighbor->h = (std::abs(goalX - nx) + std::abs(goalY - ny)) * 10;
					neighbor->f = neighbor->g + neighbor->h;
					neighbor->parent = current;
					openSet.push(neighbor);
				}
			}
		}
		// メモリ解放
		for (auto& row : nodes)
			for (auto& n : row)
				delete n;

		return path;
	}
};

