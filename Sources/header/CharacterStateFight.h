#pragma once
#include "../header/BaseCharacterState.h"
#include "../header/ITargetSelector.h"
#include "../header/BaseCharacter.h"

/*
 * Sein
 * OfficerのFightState
 */
class CharacterStateFight: public BaseCharacterState
{
public:
	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;

private:
	BaseCharacter::AttackAction* _attack;
	std::vector<BaseCharacter*> _targetCharacter;
	ITargetSelector* _selector;

	bool isAttacking = false;
	bool hasAttacked = false;

	int _attackStartCount = 0;
	int _attackHitTiming = 0;
	int _attackDuration = 60;
	int _coolTime = 1000;
	int _hitTimingOffset = 10;

	/// <summary>
	/// 攻撃を始める準備
	/// </summary>
	void StartAttack();
	/// <summary>
	/// 射程内かをチェック
	/// </summary>
	/// <param name="character"></param>
	/// <returns></returns>
	bool CheckRange(BaseCharacter* character);
};