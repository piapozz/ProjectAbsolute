#pragma once
#include "Const.h"
#include <vector>
#include "RouteSearcher.h"
#include "SecureRoom.h"
#include "BaseEntity.h"
class Vector2;
/*
* Ishihara
* �X�e�[�W�̐���
*/
class StageManager
{
public:
	// �X�e�[�W�f�[�^
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
	/// <summary>
	/// �X�e�[�W�����邩�ǂ���
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	bool CheckPosOnStage(Vector2 pos);
	/// <summary>
	/// �G�̐ݒ�
	/// </summary>
	/// <param name="entity"></param>
	/// <param name="index"></param>
	void SetEntity(BaseEntity& entity, int index){_secureRoomList[index]->SetEntity(&entity); }
private:
	// ���O�ɏ��������ꂽ�K��t���O
	std::vector<std::vector<bool>> _visited;
	std::vector<SecureRoom*> _secureRoomList;

};