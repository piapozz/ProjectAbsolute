#include "../header/ObjectManager.h"
#include "../header/BaseObject.h"

std::vector<std::vector<BaseObject*>> ObjectManager::_objectList;

void ObjectManager::Init()
{
	_objectList = std::vector<std::vector<BaseObject*>>(
		(int)ObjectType::MAX,
		std::vector<BaseObject*>((int)ObjectType::MAX,
		nullptr)
	);
}

void ObjectManager::Update()
{
	for (int i = 0, max = (int)ObjectType::MAX; i < max; i++)
	{
		for (BaseObject* obj : _objectList[i])
		{
			if (obj == nullptr) return;
			obj->Proc();
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
			if (obj == nullptr) return;
			if (obj->GetLayer() == Layer::NONE_DRAW) continue;
			obj->Draw();
		}
	}
	// 裏画面の内容を表画面に反映
	ScreenFlip ();
}

void ObjectManager::AddObject(BaseObject* obj)
{
	if(obj == nullptr) return;
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
				obj->Teardown();
				delete *it;
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
			obj->Teardown();
			delete obj;
		}
	}
	_objectList.clear();
}

BaseObject* ObjectManager::FindPosObject(Vector2 pos, ObjectType type)
{
	for (BaseObject* obj : _objectList[(int)type])
	{
		if (obj == nullptr) return nullptr;
		if (obj->GetLayer() == Layer::NONE_DRAW) continue;
		if (obj->IsSamePos(pos))
		{
			return obj;
		}
	}
	return nullptr;
}