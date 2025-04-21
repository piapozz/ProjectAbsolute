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
	virtual void Init();
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

	/// <summary>
	/// ƒ_ƒ[ƒWˆ—
	/// </summary>
	/// <param name="strength"></param>
	/// <param name="damageType"></param>
	/// <returns></returns>
	virtual int TakeDamege(int strength, Type damageType) { return -1; }
	/// <summary>
	/// ‘Ì—ÍŒ¸­ˆ—
	/// </summary>
	/// <param name="decreaseValue"></param>
	void DecreaseHealth(int decreaseValue);

	int GetHealth(){ return health; }
	void SetHealth(int value){ health = value; }

protected:
	// UŒ‚—Í
	int attack;
	// UŒ‚‘®«
	Type attackType;
	// –hŒä”{—¦
	float defenseRatio[(int)Type::MAX];
	// ‘Ì—Í
	int health;
	// Å‘å‘Ì—Í
	int maxHealth;
};

