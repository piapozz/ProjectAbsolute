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
#include "../header/UIButton.h"

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

	SectionRoom* room = new SectionRoom();
	Vector2 pos = Vector2(0, 0);
	room->Init(pos, Vector2(0, 0));
	ObjectManager::AddObject(room);

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
				Vector2 pos = Vector2(j + size / 2.0f, -(i + size / 2.0f)) * SECTION_SIZE;
				room->Init(pos, Vector2(size * SECTION_SIZE, size * SECTION_SIZE));
				ObjectManager::AddObject(room);
				UIButton* button = new UIButton();
				button->Init(pos, Vector2(size * SECTION_SIZE, size * SECTION_SIZE));
				button->SetActive(true);
				button->SetButtonText("����");
				button->SetLayer(Layer::DEBUG);
				ObjectManager::AddObject(button);
			} 
			else if (_stageData[i][j] == (int)SectionType::CORRIDOR)
			{
				// �L���𐶐�
				int size = CheckSectionSize(j, i, SectionType::CORRIDOR);
				SectionCorridor* corrider = new SectionCorridor();
				Vector2 pos = Vector2(j + size / 2.0f, -(i + 1 / 2.0f)) * SECTION_SIZE;
				corrider->Init(pos, Vector2(size * SECTION_SIZE, SECTION_SIZE));
				ObjectManager::AddObject(corrider);
				UIButton* button = new UIButton();
				button->Init(pos, Vector2(size * SECTION_SIZE, SECTION_SIZE));
				button->SetActive(true);
				button->SetButtonText("�L��");
				button->SetLayer(Layer::DEBUG);
				ObjectManager::AddObject(button);
			} 
			else if (_stageData[i][j] == (int)SectionType::CONNECT)
			{
				// �ڍ����𐶐�
				int size = CheckSectionSize(j, i, SectionType::CONNECT);
				SectionConnect* connect = new SectionConnect();
				Vector2 pos = Vector2(j + 1 / 2.0f, -(i + size / 2.0f)) * SECTION_SIZE;
				connect->Init(pos, Vector2(SECTION_SIZE, size * SECTION_SIZE));
				ObjectManager::AddObject(connect);
				UIButton* button = new UIButton();
				button->Init(pos, Vector2(SECTION_SIZE, size * SECTION_SIZE));
				button->SetActive(true);
				button->SetButtonText("�ڑ���");
				button->SetLayer(Layer::DEBUG);
				ObjectManager::AddObject(button);
			} 
			else if (_stageData[i][j] == (int)SectionType::SECURE)
			{
				// ���e���𐶐�
				int size = CheckSectionSize(j, i, SectionType::SECURE);
				SecureRoom* secure = new SecureRoom();
				Vector2 pos = Vector2(j + size / 2.0f, -(i + size / 2.0f)) * SECTION_SIZE;
				secure->Init(pos, Vector2(size * SECTION_SIZE, size * SECTION_SIZE));
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
	int y = (int)(pos.x / SECTION_SIZE);
	int x = (int)(-pos.y / SECTION_SIZE);
	// ��悪���݂��Ȃ��A�܂��͐ڑ����A���e���� false
	if (_stageData[x][y] == (int)SectionType::CONNECT || 
		_stageData[x][y] == (int)SectionType::NONE ||
		_stageData[x][y] == (int)SectionType::SECURE)
	{
		return false;
	}
	return true;
}