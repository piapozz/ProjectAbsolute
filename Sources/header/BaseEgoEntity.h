#pragma once
#include "../header/BaseEntity.h"
#include "../header/BaseCharacterState.h"
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
		: BaseEntity(layerSetting) {
	}
	virtual ~BaseEgoEntity(){}

	void Init(LayerSetting layerSetting) override;
	void Proc() override;
	inline bool IsTool() override { return false; }

protected:
	bool isRunaway;
};

