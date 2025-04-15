#pragma once
#include "../header/BaseCharacter.h"

/*
 * Sakakura
 * �G���e�B�e�B�[�̊��
 */
class BaseEntity: public BaseCharacter
{
public:
	BaseEntity(int ID)
		:_ID(ID){}
	~BaseEntity(){}

	void Init() override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

protected:
	// ��ƊJ�n���A��ƏI�����A�N���t�H�g�J�E���^�[�������Ȃǂ̊֐�
	// ����̎��e���̑O��ʉ߂����ꍇ
	// ����l�������S������
	virtual void StartOperationEvent();

private:
	int _ID;

};

