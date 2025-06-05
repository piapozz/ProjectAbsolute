#pragma once
#include "../header/BaseEgoEntity.h"

/*
 * Sakakura
 * E000
 */
class Entity_E000: public BaseEgoEntity
{
public:
	Entity_E000(){ }
	Entity_E000(LayerSetting layerSetting)
		: BaseEgoEntity(layerSetting) {
	}
	virtual ~Entity_E000(){}
	static std::string StaticTypeName() {
		return "Entity_E000";
	}

protected:
	void Init(LayerSetting layerSetting) override;
	void EndOperationEvent(int successCount) override;
};

