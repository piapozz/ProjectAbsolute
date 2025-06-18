#pragma once
#include "BaseEntity.h"
#include "BaseCharacterState.h"
#include "UI.h"
class BaseOperation;

/*
 * Sakakura
 * 通常エンティティーの基底
 */
class BaseEgoEntity: public BaseEntity
{
public:
	// 作業結果
	enum class Feeling
	{
		Good = 0,
		Normal,
		Bad,
	};

	BaseEgoEntity(){}
	BaseEgoEntity(LayerSetting layerSetting)
	{
		Init(layerSetting);
	}
	virtual ~BaseEgoEntity(){}

	void Init(LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void RunawayEvent() override { isRunaway = true; }
	inline bool IsTool() override { return false; }

protected:
	bool isRunaway;

	UIText* text;
};

