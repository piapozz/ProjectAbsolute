#pragma once
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
#include "CommonModule.h"
#include "Const.h"

// �m�[�h�N���X�iA*�p�j
class Node 
{
public:
	int x, y;
	// �X�^�[�g����̃R�X�g
	int g = 999999;   
	// �S�[���܂ł̐���R�X�g
	int h = 0;
	// ���v�R�X�g f = g + h
	int f = 0;
	Node* parent = nullptr;

	Node(int x, int y): x(x), y(y) { }
};

// �D��x�t���L���[�p ��r�֐�
struct CompareNode
{
	bool operator()(const Node* a, const Node* b) const
	{
		return a->f > b->f;
	}
};

// 4�����̈ړ��i��E���E���E�E�j
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
/*
* Ishihara
* �o�H�T��
*/
class RouteSearcher
{
public:
	/// <summary>
	/// �o�H�T������
	/// </summary>
	/// <param name="stageData"></param>
	/// <param name="start"></param>
	/// <param name="goal"></param>
	/// <returns></returns>
	static std::vector<Vector2> RouteSearch(std::vector<std::vector<int>> stageData, Vector2 start, Vector2 goal);
};

