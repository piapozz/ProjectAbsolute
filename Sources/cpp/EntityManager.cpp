#include "../header/EntityManager.h"
#include "../header/ObjectFactory.h"
#include "../header/Entity_E000.h"
#include "../header/StageManager.h"

void EntityManager::Init()
{
	// エンティティの登録
	RegisterEntity<Entity_E000>(0);
}

void EntityManager::AddEntity(int addID)
{
	EntityManagementData data = EntityManagementData();
	data.ID = addID;
	data.roomID = _entityDataList.size();
	_entityDataList.push_back(data);
}

void EntityManager::AddEntityObject()
{
	int entityCount = _entityDataList.size();
	int divisionCount = 0;
	int entityDivisionMax = StageManager::Instance().GetEntityCount(divisionCount);
	vector<BaseEntity*> entityList;
	for (int i = 0; i < entityCount; i++)
	{
		int addID = _entityDataList[i].ID;
		BaseEntity* addEntity = CreateEntity(addID);
		addEntity->SetManagementData(_entityDataList[i]);
		entityList.push_back(addEntity);
		// 区画のエンティティを生成したら配属
		if (i >= entityDivisionMax - 1 || i == (entityCount - 1))
		{
			StageManager::Instance().SetEntity(entityList, divisionCount);
			if (i != (entityCount - 1))
			{
				entityList.clear();
				divisionCount++;
				entityDivisionMax += StageManager::Instance().GetEntityCount(divisionCount);
			}
		}
	}
}

template<typename T>
void EntityManager::RegisterEntity(int ID)
{
	_entityLibrary[ID] = std::make_unique<TypeEntry<T>>();
}

BaseEntity* EntityManager::CreateEntity(int id) const
{
	auto it = _entityLibrary.find(id);
	if (it != _entityLibrary.end()) {
		return it->second->Create();
	}
	return nullptr;
}