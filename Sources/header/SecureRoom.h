#pragma once
#include "../header/BaseSection.h"
#include "../header/BaseEntity.h"

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

protected:


private:
	// 収容室のID
	int _ID;
	// 収容室の状態
	enum class State
	{
		NONE,
		SAFE,
		EMERGENCY,
	};
	State _state;
	// 収容室のエンティティー
	BaseEntity* _pEntity;
};

