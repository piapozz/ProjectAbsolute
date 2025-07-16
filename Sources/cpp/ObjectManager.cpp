#include "../header/ObjectManager.h"
#include "../header/BaseObject.h"
#include "../header/ObjectFactory.h"
#include "../header/MemoryAllocator.h"

void ObjectManager::Init()
{
	_objectList = vector<vector<vector<BaseObject*>>>(
		(int)ObjectType::MAX,
		std::vector<std::vector<BaseObject*>>(
		(int)Layer::MAX
	));
	_gameSpeed = 1;
}

void ObjectManager::Update()
{
	std::vector<BaseObject*> tempObjects;

	ForEachObject([&](BaseObject* obj) {
		tempObjects.push_back(obj);
	});

	for (int i = 0; i < _gameSpeed; i++)
	{
		for (BaseObject* obj : tempObjects)
		{
			if (obj && obj->GetActive()) obj->Proc();
		}
	}

	for (int layer = 0; layer < (int)Layer::MAX; layer++)
	{
		for (BaseObject* obj : _objectList[(int)ObjectType::SCREEN_UI][layer])
		{
			if (obj && obj->GetActive()) obj->Proc();
		}
	}
}

void ObjectManager::Draw()
{
	// 画面のクリア
	ClearDrawScreen();
	clsDx ();
	ForEachObject([](BaseObject* obj) {
		if (obj->GetTransform().IsChild()) return;
		obj->Draw();
	});
	// 裏画面の内容を表画面に反映
	ScreenFlip ();
}

void ObjectManager::ForEachObject(function<void(BaseObject*)> func)
{
	for (int type = 0; type < (int)ObjectType::MAX; type++)
	{
		for (int layer = 0; layer < (int)Layer::MAX; layer++)
		{
			for (BaseObject* obj : _objectList[type][layer])
			{
				if (obj == nullptr) continue;
				if (!obj->GetActive()) continue;
				func(obj);
			}
		}
	}
}

void ObjectManager::AddObject(BaseObject* obj)
{
	if(obj == nullptr) return;
	if (_objectList.size() == 0)
	{
		Init();
	}
	ObjectType type = obj->GetType();
	Layer layer = obj->GetLayer();
	_objectList[(int)type][(int)layer].push_back(obj);
}

void ObjectManager::RemoveObject(BaseObject* obj)
{
	if (!obj || _removedObjects.find(obj) != _removedObjects.end()) return;

	_removedObjects.insert(obj);
	obj->Teardown();

	for (int i = 0; i < (int)ObjectType::MAX; i++)
	{
		for (int j = 0; j < (int)Layer::MAX; j++)
		{
			auto& list = _objectList[i][j];
			auto it = std::find(list.begin(), list.end(), obj);
			if (it != list.end())
			{
				list.erase(it);
				ObjectFactory::Instance().Destroy(obj);
				return;
			}
		}
	}
}

void ObjectManager::AllClear()
{
	std::vector<BaseObject*> tempList;

	for (int i = 0; i < (int)ObjectType::MAX; i++)
	{
		for (int j = 0; j < (int)Layer::MAX; j++)
		{
			for (BaseObject* obj : _objectList[i][j])
			{
				if (obj)
				{
					_removedObjects.insert(obj);
					obj->Teardown();
					ObjectFactory::Instance().Destroy(obj);
				}
			}
		}
	}

	_objectList.clear();
	_removedObjects.clear();
	ObjectFactory::Instance().ClearDestroyedCache();
	Init();
}


BaseObject* ObjectManager::FindPosObject(Vector2 pos)
{
	for (int i = (int)ObjectType::SCREEN_UI; i >=0 ; i--)
	{
		BaseObject* obj = FindPosObject(pos, (ObjectType)i);
		if (obj != nullptr)
		{
			return obj;
		}
	}
	return nullptr;
}

std::vector<BaseObject*> ObjectManager::FindPosAllObject(Vector2 pos, ObjectType type)
{
	std::vector<BaseObject*> objs;
	for (int i = (int)Layer::FRONT; i >=0 ; i--)
	{
		for (BaseObject* obj : _objectList[(int)type][i])
		{
			if (obj == nullptr) continue;
			if (!obj->GetActive() || !obj->GetInteract()) continue;
			if (obj->IsSamePos(pos))
			{
				objs.push_back(obj);
			}
		}
	}
	return objs;
}

BaseObject* ObjectManager::FindPosObject(Vector2 pos, ObjectType type)
{
	for (int i = (int)Layer::FRONT; i >=0 ; i--)
	{
		for (BaseObject* obj : _objectList[(int)type][i])
		{
			if (obj == nullptr) continue;
			if (!obj->GetActive() || !obj->GetInteract()) continue;
			if (obj->IsSamePos(pos))
			{
				return obj;
			}
		}
	}
	return nullptr;
}

std::vector<BaseObject*> ObjectManager::FindRectAllObject(Vector2 pos, Vector2 size, ObjectType type)
{
	std::vector<BaseObject*> objs;
	for (int i = (int)Layer::FRONT; i >=0 ; i--)
	{
		for (BaseObject* obj : _objectList[(int)type][i])
		{
			if (obj == nullptr) continue;
			if (!obj->GetActive() || !obj->GetInteract()) continue;
			if (obj->IsSameRect(pos, size))
			{
				objs.push_back(obj);
			}
		}
	}
	return objs;
}