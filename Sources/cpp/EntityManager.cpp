#include "../header/EntityManager.h"
#include "../header/ObjectFactory.h"
#include "../header/Entity_E000.h"

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

vector<BaseEntity*> EntityManager::AddObjectEntity()
{
	int entityCount = _entityDataList.size();
	vector<BaseEntity*> entityList;
	for (int i = 0; i < entityCount; i++)
	{
		int addID = _entityDataList[i].ID;
		BaseEntity* addEntity = CreateEntity(addID);
		addEntity->SetManagementData(_entityDataList[i]);
		entityList.push_back(addEntity);
	}
	return entityList;
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