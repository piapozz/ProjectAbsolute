#pragma once
#include "Const.h"
#include <vector>
#include "../header/CommonModule.h"
#include "../header/RouteSearcher.h"
class Vector2;
/*
* Ishihara
* �X�e�[�W�̐���
*/
class StageManager
{
public:
	// �X�e�[�W�̏��
	
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
	/// ��悪�Ȃ����Ă��邩�ǂ���
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
	static std::vector<Vector2> FindPath(Vector2 start, Vector2 goal);
	/// <summary>
	/// �X�e�[�W�̃f�[�^���擾
	/// </summary>
	/// <param name="stageData"></param>
	void SetStageData(std::vector<std::vector<int>> stageData) { _stageData = stageData; }
	// �X�e�[�W�f�[�^
	static std::vector<std::vector<int>> _stageData;

private:
	// ���O�ɏ��������ꂽ�K��t���O
	std::vector<std::vector<bool>> _visited;
};