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
	SecureRoom()
		:_isMeltdown(false), _meltdownCount(0){};
	SecureRoom(BaseEntity* pEntity)
		:_pEntity(pEntity), _isMeltdown(false), _meltdownCount(0){}
	~SecureRoom(){ Teardown(); }

	void Init(Vector2 position, int size) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	/// <summary>
	/// �����g�_�E���̊J�n
	/// </summary>
	void StartMeltdown();
	void SetEntity(BaseEntity* pEntity){ _pEntity = pEntity; }

private:
	// �����g�_�E���̃J�E���g��
	int _MELTDOWN_COUNT = 60 * 60;
	// ���e���Ă���G���e�B�e�B�[
	BaseEntity* _pEntity;
	bool _isMeltdown;
	int _meltdownCount;

	/// <summary>
	/// �����g�_�E���̃J�E���g������
	/// </summary>
	void MeltdownProc();
};

