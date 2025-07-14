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
	_entityDataList.push_back(EntityManagementData());
}

void EntityManager::AddObjectEntity()
{
	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform(Vector2::zero(), Vector2::one());
	LayerSetting layer = LayerSetting(true, true, Layer::MIDDLE);
	for (int i = 0, max = _entityDataList.size(); i < max; i++)
	{
		int addID = _entityDataList[i].ID;
		CreateEntity(addID);
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