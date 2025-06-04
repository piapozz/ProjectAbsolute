#pragma once
#include "../header/BaseEgoEntity.h"

/*
 * Sakakura
 * E000
 */
class Entity_E000: public BaseEgoEntity
{
public:
	Entity_E000(){}
	virtual ~Entity_E000(){}
	static std::string StaticTypeName() {
		return "Entity_E000";
	}

	std::string GetTypeName() const override {
		return StaticTypeName();
	}

protected:
	void Init() override;
	void EndOperationEvent(int successCount) override;
};

