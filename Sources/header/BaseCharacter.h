#pragma once
#include "BaseObject.h"
#include "../header/RouteSearcher.h"
#include "../header/StateArgs.h"
#include "../header/BaseSection.h"

#include "../header/BaseController.h"

class BaseCharacterState;
class BaseAttack;
class ITargetSelector;

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

	struct AttackAction
	{
		// 対象の選択方法
		ITargetSelector* targetSelector;
		// 攻撃の種類
		BaseAttack* characterAttack;
		// 攻撃の射程
		float attackRange;
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
	/// 移動ステートに目的の部屋を使って切り替える
	/// </summary>
	/// <param name="targetPos"></param>
	/// <param name="secureRoom"></param>
	void ChangeMoveState(BaseSection* targetSection, CharacterStateID nextStateID = CharacterStateID::IDLE);
	/// <summary>
	/// 移動ステートに座標を使って切り替える
	/// </summary>
	/// <param name="targetPosition"></param>
	/// <param name="nextStateID"></param>
	void ChangeMoveState(Vector2 targetPosition, CharacterStateID nextStateID = CharacterStateID::IDLE);
	void ChangeMoveState(BaseCharacter* targetObject);
	void SetTargetCharacter(BaseCharacter* target)
	{
		targetCharacter = target;
		isFight = (target != nullptr);
	}

	void ClearTargetCharacter()
	{
		targetCharacter = nullptr;
		isFight = false;
	}

	inline bool GetIsDead(){ return isDead; }
	inline bool GetIsPanic(){ return isPanic; }
	inline bool GetIsFight(){ return isFight; }
	inline BaseSection* GetPastPosition(){ return pastRoom; }
	inline AttackStatus GetAttackStatus() { return _attackStatus; }
	inline int GetHealth(){ return health; }
	inline bool GetImpossible(){ return impossible; }
	inline CharacterGroup GetGroup(){ return _groupType; }
	inline std::vector<AttackAction*> GetAttackAction(){ return attackActions; }
	inline int GetSpeed(){ return _moveSpeed; }
	inline void SetIsDead(bool flag){ isDead = flag; }
	inline void SetIsPanic(bool flag){ isPanic = flag; }
	inline void SetIsFight(bool flag){ isFight = flag; }
	inline void SetAttackStatus(AttackStatus attackStatus){ _attackStatus = attackStatus; }
	inline void SetHealth(int value){ health = value; }
	inline void SetImpossible(bool flag){ impossible = flag; }
	inline void SetGroup(CharacterGroup groupType){ _groupType = groupType; }
	inline void SetAttackAction(AttackAction* baseAttack){ attackActions.push_back(baseAttack); }
	inline void SetSpeed(int value){ _moveSpeed = value; }

	std::vector<AttackAction*> attackActions;
	// 過去の位置
	BaseSection* pastRoom;
	BaseController* pController;
	BaseCharacterState* pCharacterState;
	CharacterStateID stateID;
	unsigned int color;
	BaseCharacter* targetCharacter;

protected:
	// 攻撃の情報
	AttackStatus _attackStatus;
	// 攻撃力
	int strength;
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
	// 死亡しているかどうか
	bool isDead;
	// パニック状態かどうか
	bool isPanic;
	// 戦闘中かどうか
	bool isFight;
private:
	int _moveSpeed;
};

