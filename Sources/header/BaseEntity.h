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

	void Init();
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	void DecreaseRunawayCount();

protected:
	// ��ƊJ�n���A��ƏI�����A�N���t�H�g�J�E���^�[�������Ȃǂ̊֐�
	// ����̎��e���̑O��ʉ߂����ꍇ
	// ����l�������S������
	virtual void StartOperationEvent(){};
	virtual void EndOperationEvent(){};
	virtual void Event(){};

private:
	int _ID;
	// �댯���x��
	int _hazardLevel;
	// �\���J�E���^�[
	int _runawayCount;
	// �ő�\���J�E���^�[
	int _maxRunawayCount;
};

