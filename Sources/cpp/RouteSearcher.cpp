#include "../header/RouteSearcher.h"
#include <algorithm> 

std::vector<Vector2> RouteSearcher::RouteSearch(std::vector<std::vector<int>> stageData, Vector2 start, Vector2 goal)
{
	int startX = (int)(start.x / SECTION_SIZE_X);
	int startY = (int)(-start.y / SECTION_SIZE_Y);
	int goalX = (int)(goal.x / SECTION_SIZE_X);
	int goalY = (int)(-goal.y / SECTION_SIZE_Y);

	if ( startY < 0 || startY >= stageData.size() || startX < 0 || startX >= stageData[startY].size() ||
		 goalY < 0 || goalY >= stageData.size() || goalX < 0 || goalX >= stageData[goalY].size())
	{
		// 範囲外の場合は空のベクターを返す
		return std::vector<Vector2>();
	}
	// ステージデータが空の場合は空のベクターを返す
	if (stageData.empty()) return std::vector<Vector2>();
	// スタートとゴールのタイルが同じ場合はスタートを返す
	if (startX == goalX && startY == goalY)
	{
		return std::vector<Vector2>{ Vector2(SECTION_SIZE_X / 2 + (startX * SECTION_SIZE_X), (-startY * SECTION_SIZE_Y) - (SECTION_SIZE_Y)) };
	}

	std::vector<std::vector<Node*>> nodes(stageData.size(), std::vector<Node*>(stageData[0].size(), nullptr));
	std::priority_queue<Node*, std::vector<Node*>, CompareNode> openSet;
	std::vector<Vector2> path;

	Node* startNode = new Node(startX, startY);
	startNode->g = 0;
	startNode->h = (std::abs(goalX - startX) + std::abs(goalY - startY)) * 10;
	startNode->f = startNode->g + startNode->h;
	openSet.push(startNode);
	nodes[startY][startX] = startNode;

	while (!openSet.empty())
	{
		Node* current = openSet.top();
		openSet.pop();

		if (current->x == goalX && current->y == goalY)
		{
			while (current != nullptr)
			{
				path.push_back(Vector2(SECTION_SIZE_X / 2 + (current->x * SECTION_SIZE_X), (-current->y * SECTION_SIZE_Y) - (SECTION_SIZE_Y)));
				current = current->parent;
			}
			break;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = current->x + dx[i];
			int ny = current->y + dy[i];

			// 範囲外チェック（stageDataアクセス前に必ず行う）
			if ( ny < 0 || ny >= stageData.size() || nx < 0 || nx >= stageData[ny].size())
				continue;
			if (current->x < 0 || current->x >= stageData[current->y].size() || current->y < 0 || current->y >= stageData.size())
				continue;

			int tile = stageData[ny][nx];
			int currentTile = stageData[current->y][current->x];

			// 通れないタイル
			if (tile == (int)SectionType::NONE) continue;

			int dyMove = ny - current->y;
			int dxMove = nx - current->x;

			// 接続部に関する通行ルール
			if (currentTile == (int)SectionType::CONNECT || tile == (int)SectionType::CONNECT)
			{
				bool isVerticalMove = (dyMove != 0 && dxMove == 0);
				if (!isVerticalMove)
					continue;
			}

			if (nodes[ny][nx] == nullptr)
			{
				nodes[ny][nx] = new Node(nx, ny);
			}
			Node* neighbor = nodes[ny][nx];
			int cost = current->g + 10;

			if (cost < neighbor->g)
			{
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

    std::reverse(path.begin(), path.end());
	// 反転したpathを返す
	// スタートを除外
	path.erase(path.begin());
    return path;
}