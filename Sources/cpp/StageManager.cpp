#include "../header/StageManager.h"
#include "../header/SectionRoom.h"
#include "../header/SectionCorridor.h"
#include "../header/SectionConnect.h"
#include "../header/SecureRoom.h"
#include "../header/Const.h"
#include "../header/ObjectManager.h"
#include "../header/CommonModule.h"
#include "../header/RouteSearcher.h"
#include "../header/PhaseMain.h"

std::vector<std::vector<int>> StageManager::_stageData;

StageManager::~StageManager() 
{
	//���e���f�[�^�̉��
	for (BaseObject* secure : _secureRoomList)
	{		
		secure->Teardown();
		delete secure;
	}
}

void StageManager::Init()
{  
	_secureRoomList.clear();
}
  
void StageManager::CreateStage()
{
	// �g�p�O�� visited ��������
	_visited = std::vector<std::vector<bool>>(
		// _stageData �̍s���ɍ��킹��
		STAGE_SIZE,
		// _stageData �̗񐔂ɍ��킹��
		std::vector<bool>(STAGE_SIZE, false) 
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
				SecureRoom* secure = new SecureRoom();
				secure->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(secure);
				// ���e���̃��X�g�ɒǉ�
				_secureRoomList.push_back(secure);
			}
		}
	}
}

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
	count += CheckSectionSize(x, y - 1, type);
	count += CheckSectionSize(x, y + 1, type);
	count += CheckSectionSize(x - 1, y, type);
	count += CheckSectionSize(x + 1, y, type);

	return count;
}

std::vector<Vector2> StageManager::FindPath(Vector2 start, Vector2 goal)
{
	// �X�e�[�W�f�[�^�̏�����
	return RouteSearcher::RouteSearch(_stageData, start, goal);
}

bool StageManager::CheckPosOnStage(Vector2 pos)
{
	// �X�e�[�W�͈̔͊O�̏ꍇ�� false ��Ԃ�
	if (pos.x < 0 || pos.x >= STAGE_SIZE * SECTION_SIZE ||
		pos.y < -STAGE_SIZE * SECTION_SIZE || pos.y > 0)
	{
		return false;
	}
	// ��悪���݂��Ȃ��A�܂��͐ڑ����� false
	if (_stageData[(int)(-pos.y / SECTION_SIZE)][(int)(pos.x / SECTION_SIZE)] == (int)SectionType::CONNECT || 
		_stageData[(int)(-pos.y / SECTION_SIZE)][(int)(pos.x / SECTION_SIZE)] == (int)SectionType::NONE)
	{
		return false;
	}
	return true;
}