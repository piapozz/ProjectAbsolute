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

protected:
	void Init(){};
	void EndOperationEvent(int successCount) override;
};

