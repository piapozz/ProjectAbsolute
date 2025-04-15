#include "../header/StageCreator.h"
#include "../header/SectionRoom.h"
#include "../header/SectionCorridor.h"
#include "../header/SectionConnect.h"
#include "../header/SecureRoom.h"
#include "../header/Const.h"
#include "../header/ObjectManager.h"

void StageCreator::CreateStage()
{
	// ステージの生成
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (_stageData[i][j] == (int)SectionType::ROOM)
			{
				// 部屋を生成
				SectionRoom* room = new SectionRoom();
				room->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(room);
			} 
			else if (_stageData[i][j] == (int)SectionType::CORRIDOR)
			{
				// 廊下を生成
				SectionCorridor* corrider = new SectionCorridor();
				corrider->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(corrider);
			} 
			else if (_stageData[i][j] == (int)SectionType::CONNECT)
			{
				// 接合部を生成
				SectionConnect* connect = new SectionConnect();
				connect->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(connect);
			} 
			else if (_stageData[i][j] == 4)
			{
				// 収容所を生成
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