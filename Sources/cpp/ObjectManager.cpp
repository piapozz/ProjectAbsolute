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
	for (int i = 0; i < _gameSpeed; i++)
	{
		ForEachObject([](BaseObject* obj) {
			obj->Proc();
		});
	}
	for (int layer = 0; layer < (int)Layer::MAX; layer++)
	{
		for (BaseObject* obj : _objectList[(int)ObjectType::SCREEN_UI][layer])
		{
			if (obj == nullptr) continue;
			if (!obj->GetActive()) continue;
			obj->Proc();
		}
	}
}

void ObjectManager::Draw()
{
	// 画面のクリア
	ClearDrawScreen();
	clsDx ();
	ForEachObject([](BaseObject* obj) {
		obj->Draw();
	});
	for (int layer = 0; layer < (int)Layer::MAX; layer++)
	{
		for (BaseObject* obj : _objectList[(int)ObjectType::SCREEN_UI][layer])
		{
			if (obj == nullptr) continue;
			if (!obj->GetActive()) continue;
			obj->Draw();
		}
	}
	// 裏画面の内容を表画面に反映
	ScreenFlip ();
}

void ObjectManager::ForEachObject(function<void(BaseObject*)> func)
{
	for (int type = 0; type < (int)ObjectType::SCREEN_UI; type++)
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
	for (int i = 0, max = (int)ObjectType::MAX; i < max; i++)
	{
		for (int j = 0, max = (int)Layer::MAX; j < max; j++)
		{
			for (auto it = _objectList[i][j].begin(); it != _objectList[i][j].end(); ++it)
			{
				if (*it == obj)
				{
					ObjectFactory::Instance().Destroy(obj);
					_objectList[i][j].erase(it);
					return;
				}
			}
		}
	}
}

void ObjectManager::AllClear()
{
	for (int i = 0, max = (int)ObjectType::MAX; i < max; i++)
	{
		for (int j = 0, max = (int)Layer::MAX; j < max; j++)
		{
			for (BaseObject* obj : _objectList[i][j])
			{
				if (obj == nullptr) continue;
				ObjectFactory::Instance().Destroy(obj);
			}
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
	for (int j = 0, max = (int)Layer::MAX; j < max; j++)
	{
		for (BaseObject* obj : _objectList[(int)type][j])
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
	for (int j = 0, max = (int)Layer::MAX; j < max; j++)
	{
		for (BaseObject* obj : _objectList[(int)type][j])
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