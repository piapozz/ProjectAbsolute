#pragma once
#include "../header/BaseCharacter.h"

/*
 * Sakakura
 * エンティティーの基底
 */
class BaseEntity: public BaseCharacter
{
public:
	BaseEntity(int ID)
		:_ID(ID){}
	~BaseEntity(){}

	void Init() override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

protected:

private:
	int _ID;

};

