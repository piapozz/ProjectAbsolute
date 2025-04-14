#include "../header/ObjectManager.h"
#include "../header/BaseObject.h"


void ObjectManager::Init()
{
	_objectList.clear();
}

void ObjectManager::Update()
{
	for(BaseObject* obj : _objectList)
	{
		if(obj == nullptr) return;
		obj->Proc();
	}
	_objectList[1]->Proc();
}

void ObjectManager::Draw()
{
	for(BaseObject* obj : _objectList)
	{
		if(obj == nullptr) return;
		if(obj->GetLayer() == Layer::NONE_DRAW) continue;
		obj->Draw();
	}
}

void ObjectManager::AddObject(BaseObject* obj)
{
	if(obj == nullptr) return;
	_objectList.push_back(obj);
}

void ObjectManager::RemoveObject(BaseObject* obj)
{
	if(obj == nullptr) return;
	for(auto it = _objectList.begin(); it != _objectList.end(); ++it)
	{
		if(*it == obj)
		{
			obj->Teardown();
			delete *it;
			_objectList.erase(it);
			break;
		}
	}
}
