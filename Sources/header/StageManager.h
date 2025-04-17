#pragma once
#include "Const.h"
#include <vector>
class Vector2;
class RouteSearcher;
/*
* Ishihara
* �X�e�[�W�̐���
*/
class StageManager
{
public:
	// �X�e�[�W�̏��
	static std::vector<std::vector<int>> _stageData;
	
	StageManager() { Init(); }
	~StageManager();

	/// <summary>
	/// ������
	/// </summary>
	void Init();
	/// <summary>
	/// �X�e�[�W����
	/// </summary>
	void CreateStage();
	/// <summary>
	/// ��悇���Ȃ����Ă��邩�ǂ���
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="type"></param>
	/// <returns></returns>
	int CheckSectionSize(int x, int y, SectionType type);
	/// <summary>
	/// A* �A���S���Y���Ōo�H��T������
	/// </summary>
	/// <param name="start">�X�^�[�g�ʒu�i���[���h���W�j</param>
	/// <param name="goal">�S�[���ʒu�i���[���h���W�j</param>
	/// <returns>Node* �̌o�H���X�g�i�S�[������X�^�[�g�����j</returns>
	std::vector<Vector2> FindPath(Vector2 start, Vector2 goal);
private:
	// ���O�ɏ��������ꂽ�K��t���O
	std::vector<std::vector<bool>> _visited;
	RouteSearcher* _routeSearcher;
};

