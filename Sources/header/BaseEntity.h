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
	// 作業開始時、作業終了時、クリフォトカウンター減少時などの関数
	// 特定の収容室の前を通過した場合
	// 特定人数が死亡した時
	virtual void StartOperationEvent();

private:
	int _ID;

};

