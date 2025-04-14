#pragma once
#include "../header/BaseSection.h"
#include "../header/BaseEntity.h"
#include "../header/Operation.h"

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

	/// <summary>
	/// �X�e�[�g�̐ݒ�
	/// </summary>
	/// <param name="operation"></param>
	void SetState(State setState);

private:
	// ���݂̃X�e�[�g
	State _currentState;
	// ���e���Ă���G���e�B�e�B�[
	BaseEntity* _pEntity;
	// ���
	Operation* _pOperation;

	/// <summary>
	/// ��Ƃ̏���
	/// </summary>
	void OperationProc();
};

