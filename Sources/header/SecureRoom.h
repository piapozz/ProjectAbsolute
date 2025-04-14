#pragma once
#include "../header/BaseSection.h"
#include "../header/BaseEntity.h"

/*
 * Sakakura
 * ���e��
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
	// ���e����ID
	int _ID;
	// ���e���̏��
	enum class State
	{
		NONE,
		SAFE,
		EMERGENCY,
	};
	State _state;
	// ���e���̃G���e�B�e�B�[
	BaseEntity* _pEntity;
};

