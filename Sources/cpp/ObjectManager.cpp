#include "../header/ObjectManager.h"
#include "../header/BaseObject.h"
#include "../header/ObjectFactory.h"
#include "../header/MemoryAllocator.h"

void ObjectManager::Init()
{
	_objectList = std::vector<std::vector<BaseObject*>>(
		(int)ObjectType::MAX
	);
	_gameSpeed = 1;
}

void ObjectManager::Update()
{
	for (int i = 0; i < _gameSpeed; i++)
	{
		for (int i = 0, max = (int)ObjectType::MAX; i < max; i++)
		{
			for (BaseObject* obj : _objectList[i])
			{
				if (obj == nullptr) continue;
				obj->Proc();
			}
		}
	}
}

void ObjectManager::Draw()
{
	// 画面のクリア
	ClearDrawScreen ();
	clsDx ();
	for (int i = 0, max = (int)ObjectType::MAX; i < max; i++)
	{
		for (BaseObject* obj : _objectList[i])
		{
			if (obj == nullptr) continue;
			if (obj->GetActive()) continue;
			obj->Draw();
		}
	}
	// 裏画面の内容を表画面に反映
	ScreenFlip ();
}

void ObjectManager::AddObject(BaseObject* obj)
{
	if(obj == nullptr) return;
	if (_objectList.size() == 0)
	{
		Init();
	}
	ObjectType type = obj->GetType();
	_objectList[(int)type].push_back(obj);
}

void ObjectManager::RemoveObject(BaseObject* obj)
{
	for (int i = 0, max = (int)ObjectType::MAX; i < max; i++)
	{
		for (auto it = _objectList[i].begin(); it != _objectList[i].end(); ++it)
		{
			if (*it == obj)
			{
				ObjectFactory::Instance().Destroy(obj);
				_objectList[i].erase(it);
				break;
			}
		}
	}
}

void ObjectManager::AllClear()
{
	for (int i = 0, max = (int)ObjectType::MAX; i < max; i++)
	{
		for (BaseObject* obj : _objectList[i])
		{
			if (obj == nullptr) continue;
			ObjectFactory::Instance().Destroy(obj);
		}
	}
	_objectList.clear();
}

BaseObject* ObjectManager::FindPosObject(Vector2 pos)
{
	for (int i = 0, max = (int)ObjectType::MAX; i < max; i++)
	{
		BaseObject* obj = FindPosObject(pos, (ObjectType)i);
		if (obj != nullptr)
		{
			return obj;
		}
	}
	return nullptr;
}

BaseObject* ObjectManager::FindPosObject(Vector2 pos, ObjectType type)
{
	for (BaseObject* obj : _objectList[(int)type])
	{
		if (obj == nullptr) continue;
		if (obj->GetActive() || obj->GetInteract()) continue;
		if (obj->IsSamePos(pos))
		{
			return obj;
		}
	}

	return nullptr;
}

std::vector<BaseObject*> ObjectManager::FindRectAllObject(Vector2 pos, Vector2 size, ObjectType type)
{
	std::vector<BaseObject*> objs;
	for (BaseObject* obj : _objectList[(int)type])
	{
		if (obj == nullptr) continue;
		if (obj->GetActive() || obj->GetInteract()) continue;
		if (obj->IsSameRect(pos, size))
		{
			objs.push_back(obj);
		}
	}
	return objs;
}