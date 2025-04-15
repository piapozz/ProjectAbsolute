#pragma once
#include "BaseObject.h"
/*
* Ishihara
* ƒLƒƒƒ‰ƒNƒ^[‚ÌŠî’ê
*/
class BaseCharacter: public BaseObject
{
public:
	BaseCharacter() {}
	BaseCharacter(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseCharacter(Layer setLayer,int setDrawHandle)
		: BaseObject(setLayer,setDrawHandle) {}
	BaseCharacter(const BaseCharacter& obj)
		: BaseObject(obj) {}
	~BaseCharacter() {}

	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Init() override;
	/// <summary>
	/// ƒAƒbƒvƒf[ƒg
	/// </summary>
	void Proc() override;
	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw() override;
	/// <summary>
	/// ”jŠü
	/// </summary>
	void Teardown() override;
	// ˆÚ“®
	// UŒ‚
	// €–S
	// ì‹Æ

protected:
	// UŒ‚—Í
	int attack;
	// UŒ‚‘®«
	Type attackType;
	// –hŒä”{—¦
	float defenseRatio[(int)Type::MAX];
	int health;
	// Å‘å‘Ì—Í
	int maxHealth;
};

