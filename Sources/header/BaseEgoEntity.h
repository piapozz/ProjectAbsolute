#pragma once
#include "../header/BaseEntity.h"
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
	virtual ~BaseEgoEntity(){}

	void Init() override;
	void Proc() override;
	inline bool IsTool() override { return false; }
};

