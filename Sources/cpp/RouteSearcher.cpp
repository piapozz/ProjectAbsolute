#include "../header/RouteSearcher.h"
#include <algorithm> 

std::vector<Vector2> RouteSearcher::RouteSearch(std::vector<std::vector<int>> stageData, Vector2 start, Vector2 goal)
{
	int startX = (int)(start.x / SECTION_SIZE);
	int startY = (int)(-start.y / SECTION_SIZE);
	int goalX = (int)(goal.x / SECTION_SIZE);
	int goalY = (int)(-goal.y / SECTION_SIZE);

	if (startX < 0 || startX > STAGE_SIZE || startY < 0 || startY > STAGE_SIZE ||
		goalX < 0 || goalX > STAGE_SIZE || goalY < 0 || goalY > STAGE_SIZE) {
		// �͈͊O�̏ꍇ�͋�̃x�N�^�[��Ԃ�
		return std::vector<Vector2>();
	}
	// �X�e�[�W�f�[�^����̏ꍇ�͋�̃x�N�^�[��Ԃ�
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
				path.push_back(Vector2(SECTION_SIZE / 2 + (current->x * SECTION_SIZE),(-current->y * SECTION_SIZE) - (SECTION_SIZE / 2)));
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
			// �ʂ�Ȃ��^�C��
			if (tile == 0) continue; 

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
	// ���������
	for (auto& row : nodes)
	for (auto& n : row)
	delete n;

    std::reverse(path.begin(), path.end()); // reverse�֐����Ăяo����path�𔽓]
	// ���]����path��Ԃ�
    return path;
}