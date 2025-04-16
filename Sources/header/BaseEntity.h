#pragma once
#include "../header/BaseCharacter.h"

/*
 * Sakakura
 * �G���e�B�e�B�[�̊��
 */
class BaseEntity: public BaseCharacter
{
public:
	BaseEntity(){}
	BaseEntity(int ID)
		:masterID(ID), interactOfficerID(-1){}
	virtual ~BaseEntity(){}

	void Init();
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	/// <summary>
	/// �\���J�E���^�[������������
	/// </summary>
	void DecreaseRunawayCount();
	/// <summary>
	/// �\���J�E���^�[�̃Z�b�g
	/// </summary>
	/// <param name="count"></param>
	inline void SetRunawayCount(int count){ runawayCount = count; }
	/// <summary>
	/// �\���C�x���g
	/// </summary>
	virtual void RunawayEvent(){};
	/// <summary>
	/// �c�[�����ۂ�
	/// </summary>
	virtual bool IsTool() = 0;
	virtual bool CanMeltdown() = 0;

protected:
	// �}�X�^�[ID
	int masterID;
	// �댯���x��
	int hazardLevel;
	// �\���J�E���^�[
	int runawayCount;
	// �ő�\���J�E���^�[
	int maxRunawayCount;
	// �C���^���N�g���̐E��ID
	int interactOfficerID;
};

