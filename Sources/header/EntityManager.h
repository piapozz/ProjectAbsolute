#pragma once
#include <vector>
#include <unordered_map>
#include <functional>
#include <memory>
#include "../header/CommonModule.h"
#include "../header/ObjectFactory.h"
#include "../header/Const.h"
class BaseEntity;

class EntityManager
{
public:
	EntityManager(){ Init(); }
	~EntityManager(){}

	void Init();

	static EntityManager& Instance() {
		static EntityManager instance;
		return instance;
	}

	void AddEntity(int addID);
	void AddEntityObject();

private:
	template<typename T>
	void RegisterEntity(int ID);

	// Às‚É ID ‚É‰‚¶‚Ä¶¬i–ˆ‰ñj
	BaseEntity* CreateEntity(int id) const;

	struct ITypeEntry
	{
		virtual BaseEntity* Create() const = 0;
		virtual ~ITypeEntry() = default;
	};

	template<typename T>
	struct TypeEntry : ITypeEntry
	{
		BaseEntity* Create() const override
		{
			LayerSetting layer = LayerSetting(true, true, Layer::MIDDLE);
			return ObjectFactory::Instance().CreateWithArgs<T>(layer);
		}
	};

	std::unordered_map<int, std::unique_ptr<ITypeEntry>> _entityLibrary;
	std::vector<EntityManagementData> _entityDataList;
};

