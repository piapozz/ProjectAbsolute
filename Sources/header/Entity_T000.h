#pragma once
#include "../header/BaseToolEntity.h"

/*
 * Ishihara
 * T000
 */
class Entity_T000 : public BaseToolEntity
{
public:
	Entity_T000(){ }
	Entity_T000(ToolType setType, LayerSetting layerSetting)
		: BaseToolEntity(setType, layerSetting) {
		Init(layerSetting);
	}
	virtual ~Entity_T000(){
	}
	static std::string StaticTypeName() {
		return "Entity_T000";
	}

protected:
	void Init(LayerSetting layerSetting) override;
	void EndOperationEvent(int successCount) override;
};

