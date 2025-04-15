#pragma once
#include "../header/BaseSection.h"
#include "../header/BaseEntity.h"
#include "../header/BaseOperation.h"

/*
 * Sakakura
 * 収容室
 */
class SecureRoom: public BaseSection
{
public:
	SecureRoom(BaseEntity* pEntity)
		:_pEntity(pEntity){ Init(); }
	~SecureRoom(){ Teardown(); }

	void Init();
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	/// <summary>
	/// ステートの設定
	/// </summary>
	/// <param name="operation"></param>
	void SetState(State setState);

private:
	// 現在のステート
	State _currentState;
	// 収容しているエンティティー
	BaseEntity* _pEntity;
	// 作業
	BaseOperation* _pOperation;

	/// <summary>
	/// 作業の処理
	/// </summary>
	void OperationProc();
};

