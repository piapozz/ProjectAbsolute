#include "../header/StageManager.h"
#include "../header/SectionRoom.h"
#include "../header/SectionCorridor.h"
#include "../header/SectionConnect.h"
#include "../header/SecureRoom.h"
#include "../header/Const.h"
#include "../header/ObjectManager.h"
#include "../header/CommonModule.h"
#include "../header/RouteSearcher.h"

StageManager::~StageManager() 
{
	// �񎟌��x�N�^�[���N���A
	for (auto& row : _stageData){ row.clear(); }
	_stageData.clear();
	for (auto& row : _visited){ row.clear(); }
	_visited.clear();

	delete _routeSearcher;
}

void StageManager::Init(){  
   // �X�e�[�W�f�[�^�̏�����  
   _stageData = std::vector<std::vector<int>>{ // �C��: std::vector ���g�p���ē񎟌��z���������  
       {1, 2, 2, 2, 2, 2, 1},  
       {3, 4, 0, 0, 0, 0, 3},  
       {3, 0, 0, 0, 0, 0, 3},  
       {1, 2, 2, 0, 2, 2, 1},  
       {3, 0, 0, 0, 0, 0, 3},  
       {3, 0, 0, 0, 0, 0, 3},  
       {1, 2, 2, 2, 2, 2, 1},  
   };  

   _routeSearcher = new RouteSearcher();
}
  
void StageManager::CreateStage()
{
	// �g�p�O�� visited ��������
	_visited = std::vector<std::vector<bool>>(
		STAGE_SIZE, // _stageData �̍s���ɍ��킹��
		std::vector<bool>(STAGE_SIZE, false) // _stageData �̗񐔂ɍ��킹��
		);

	// �X�e�[�W�̐���
	for (int i = 0; i < STAGE_SIZE; ++i)
	{
		for (int j = 0; j < STAGE_SIZE; ++j)
		{
			if (_visited[i][j]) continue; // ���ɖK�ꂽ�ꏊ�̓X�L�b�v
			// �Z�N�V�����̎�ނɉ����ď����𕪊�
			if (_stageData[i][j] == (int)SectionType::ROOM)
			{
				// �����𐶐�
				int size = CheckSectionSize(j, i, SectionType::ROOM);
				SectionRoom* room = new SectionRoom();
				room->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), size);
				ObjectManager::AddObject(room);
			} 
			else if (_stageData[i][j] == (int)SectionType::CORRIDOR)
			{
				// �L���𐶐�
				int size = CheckSectionSize(j, i, SectionType::CORRIDOR);
				SectionCorridor* corrider = new SectionCorridor();
				corrider->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), size);
				ObjectManager::AddObject(corrider);
			} 
			else if (_stageData[i][j] == (int)SectionType::CONNECT)
			{
				// �ڍ����𐶐�
				int size = CheckSectionSize(j, i, SectionType::CONNECT);
				SectionConnect* connect = new SectionConnect();
				connect->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), size);
				ObjectManager::AddObject(connect);
			} 
			else if (_stageData[i][j] == 4)
			{
				// ���e���𐶐�
				/*SecureRoom* secure = new SecureRoom();
				secure->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(secure);*/
				SectionRoom* room = new SectionRoom();
				room->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 0);
				ObjectManager::AddObject(room);
			}
		}
	}
}

/// <summary>
/// �����Ȃ����Ă��邩�𒲂ׂ�
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="type"></param>
/// <returns></returns>
int StageManager::CheckSectionSize(int x, int y, SectionType type)
{
	// �͈͊O�`�F�b�N
	if (y < 0 || y >= STAGE_SIZE || x < 0 || x >= STAGE_SIZE)
		return 0;
	// ���ɖK��Ă��� or ��ނ��قȂ�ꍇ�͖���
	if (_visited[y][x] || _stageData[y][x] != (int)type)
		return 0;
	_visited[y][x] = true;

	int count = 1;
	// �㉺���E�ɍċA
	count += CheckSectionSize(x, y - 1, type); // ��
	count += CheckSectionSize(x, y + 1, type); // ��
	count += CheckSectionSize(x - 1, y, type); // ��
	count += CheckSectionSize(x + 1, y, type); // �E

	return count;
}

std::vector<Vector2> StageManager::FindPath(Vector2 start, Vector2 goal)
{
	return _routeSearcher->RouteSearch(_stageData, start, goal);
}
