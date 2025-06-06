#pragma once
#include "BaseObject.h"
#include "../header/RouteSearcher.h"
#include "../header/StateArgs.h"
#include "../header/BaseSection.h"

class BaseCharacterState;
class BaseAttack;

/*
* Ishihara
* キャラクターの基底
*/
class BaseCharacter: public BaseObject
{
public:
	struct AttackStatus
	{
		// 攻撃力
		int attack;
		// 攻撃属性
		Type damageType;
	};

	BaseCharacter() {}
	BaseCharacter(LayerSetting layerSetting) {
		Init(layerSetting);
	}
	BaseCharacter(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseCharacter(Layer setLayer,int setDrawHandle)
		: BaseObject(setLayer,setDrawHandle) {}
	BaseCharacter(const BaseCharacter& obj)
		: BaseObject(obj) {}
	~BaseCharacter() {}

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init(LayerSetting layerSetting);
	/// <summary>
	/// アップデート
	/// </summary>
	void Proc() override;
	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;
	/// <summary>
	/// 破棄
	/// </summary>
	void Teardown() override;
	// 移動
	// 攻撃
	// 死亡
	// 作業

	/// <summary>
	/// ダメージ処理
	/// </summary>
	/// <param name="strength"></param>
	/// <param name="damageType"></param>
	/// <returns></returns>
	virtual void TakeDamage(int strength, Type damageType)
	{
		float index;
		index = strength * defenseRatio[(int)damageType];
		DecreaseHealth(ceil(index));
	}
	/// <summary>
	/// 区画へ移動する
	/// </summary>
	/// <param name="targetSection"></param>
	/// <returns></returns>
	bool Move(BaseSection* targetSection);
	/// <summary>
	/// 細かい座標に移動する
	/// </summary>
	/// <param name="targetPosition"></param>
	/// <returns></returns>
	bool Move(Vector2 targetPosition);
	/// <summary>
	/// 体力減少処理
	/// </summary>
	/// <param name="decreaseValue"></param>
	void DecreaseHealth(int decreaseValue);
	/// <summary>
	/// キャラクターのステートの切り替え
	/// </summary>
	/// <param name="stateID"></param>
	/// <param name="args"></param>
	void ChangeState(CharacterStateID stateID, StateArgs* args = nullptr);
	/// <summary>
	/// 移動ステートを簡単に切り替える関数
	/// </summary>
	/// <param name="targetPos"></param>
	/// <param name="secureRoom"></param>
	void ChangeMoveState(BaseSection* targetSection);

	Vector2 GetPosition(){ return position; }
	BaseSection* GetPastPosition(){ return pastRoom; }
	void SetAttackStatus(AttackStatus attackStatus){ _attackStatus = attackStatus; }
	AttackStatus GetAttackStatus() { return _attackStatus; }
	void SetHealth(int value){ health = value; }
	int GetHealth(){ return health; }
	void SetImpossible(bool flag){ impossible = flag; }
	bool GetImpossible(){ return impossible; }
	void SetGroup(CharacterGroup groupType){ _groupType = groupType; }
	CharacterGroup GetGroup(){ return _groupType; }
	void SetAttack(BaseAttack* baseAttack){ characterAttack = baseAttack; }
	BaseAttack* GetAttack(){ return characterAttack; }

	// 過去の位置
	BaseSection* pastRoom;
	BaseCharacterState* pCharacterState;
	CharacterStateID stateID;
	BaseAttack* characterAttack;
	unsigned int color;

protected:
	// 攻撃の情報
	AttackStatus _attackStatus;
	// 防御倍率
	float defenseRatio[(int)Type::MAX];
	// 体力
	int health;
	// 最大体力
	int maxHealth;
	// ステートを遷移できるか
	bool impossible;
	// キャラクターの陣営
	CharacterGroup _groupType;

private:

};

