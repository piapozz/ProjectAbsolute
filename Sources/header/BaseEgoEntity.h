#pragma once
#include "../header/BaseEntity.h"
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
	virtual ~BaseEgoEntity(){}

	void Init() override;
	void Proc() override;
	inline bool IsTool() override { return false; }
};

