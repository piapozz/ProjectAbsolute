#pragma once
#include "BaseObject.h"
#include "../header/RouteSearcher.h"
#include "../header/StateArgs.h"

class BaseCharacterState;

/*
* Ishihara
* キャラクターの基底
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
	/// 初期化
	/// </summary>
	virtual void Init();
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
	virtual int TakeDamege(int strength, Type damageType) { return -1; }
	/// <summary>
	/// 体力減少処理
	/// </summary>
	/// <param name="decreaseValue"></param>
	void DecreaseHealth(int decreaseValue);
	void ChangeState(OfficerStateID stateID, StateArgs* args = nullptr);
	void ChangeMoveState(Vector2 targetPos, SecureRoom* secureRoom = nullptr);
	bool CharacterMove(std::vector<Vector2> targetPosList, float speed);

	void SetPosition(Vector2 setPosition){ position = setPosition; }
	Vector2 GetPosition(){ return position; }
	Vector2 GetPastPosition(){ return _pastPosition; }
	int GetHealth(){ return health; }
	void SetHealth(int value){ health = value; }
	void SetImpossible(bool flag) { impossible = flag; }
	bool GetImpossible(){ return impossible; }

	// 過去の位置
	Vector2 _pastPosition;
	BaseCharacterState* pCharacterState;
	unsigned int color;

protected:
	// 攻撃力
	int attack;
	// 攻撃属性
	Type attackType;
	// 防御倍率
	float defenseRatio[(int)Type::MAX];
	// 体力
	int health;
	// 最大体力
	int maxHealth;
	// ステートを遷移できるか
	bool impossible;

private:
	int _moveListIndex;

};

