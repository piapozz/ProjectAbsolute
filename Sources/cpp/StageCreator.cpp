#include "../header/StageCreator.h"
#include "../header/SectionRoom.h"
#include "../header/SectionCorridor.h"
#include "../header/SectionConnect.h"
#include "../header/SecureRoom.h"
#include "../header/Const.h"
#include "../header/ObjectManager.h"

void StageCreator::CreateStage()
{
	// �X�e�[�W�̐���
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (_stageData[i][j] == (int)SectionType::ROOM)
			{
				// �����𐶐�
				SectionRoom* room = new SectionRoom();
				room->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(room);
			} 
			else if (_stageData[i][j] == (int)SectionType::CORRIDOR)
			{
				// �L���𐶐�
				SectionCorridor* corrider = new SectionCorridor();
				corrider->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(corrider);
			} 
			else if (_stageData[i][j] == (int)SectionType::CONNECT)
			{
				// �ڍ����𐶐�
				SectionConnect* connect = new SectionConnect();
				connect->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(connect);
			} 
			else if (_stageData[i][j] == 4)
			{
				// ���e���𐶐�
				/*SecureRoom* secure = new SecureRoom();
				secure->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(secure);*/
				SectionRoom* room = new SectionRoom();
				room->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(room);
			}
		}
	}

}