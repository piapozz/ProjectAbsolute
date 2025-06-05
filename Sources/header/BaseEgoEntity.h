#pragma once
#include "../header/BaseEntity.h"
#include "../header/BaseCharacterState.h"
class BaseOperation;

/*
 * Sakakura
 * �ʏ�G���e�B�e�B�[�̊��
 */
class BaseEgoEntity: public BaseEntity
{
public:
	// ��ƌ���
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

