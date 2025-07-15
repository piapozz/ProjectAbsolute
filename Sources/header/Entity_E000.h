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
		Init(layerSetting);
	}
	virtual ~Entity_E000(){}
	static std::string StaticTypeName() {
		return "Entity_E000";
	}
	void Respawn() override;

protected:
	void Init(LayerSetting layerSetting) override;
	void Proc() override;
	void EndOperationEvent(int successCount) override;

private:
	void RunawayEvent() override;

};

