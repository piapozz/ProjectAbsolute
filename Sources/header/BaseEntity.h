#pragma once
#include "../header/BaseCharacter.h"

/*
 * Sakakura
 * �G���e�B�e�B�[�̊��
 */
class BaseEntity: public BaseCharacter
{
public:
	enum class Feeling
	{
		Good = 0,
		Normal,
		Bad,
	};

	BaseEntity(){}
	BaseEntity(int ID)
		:_ID(ID){}
	~BaseEntity(){}

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
	inline void SetRunawayCount(int count){ _runawayCount = count; }
	// ��ƊJ�n���A��ƏI�����A�N���t�H�g�J�E���^�[�������Ȃǂ̊֐�
	// ����̎��e���̑O��ʉ߂����ꍇ
	// ����l�������S������
	
	/// <summary>
	/// ��ƊJ�n���C�x���g
	/// </summary>
	virtual void StartOperationEvent(){};
	/// <summary>
	/// ��ƏI�����C�x���g
	/// </summary>
	/// <param name="successCount"></param>
	virtual void EndOperationEvent(int successCount){};
	/// <summary>
	/// �\���C�x���g
	/// </summary>
	virtual void RunawayEvent(){};
	virtual void IsTool() = 0;

protected:

private:
	int _ID;
	// �댯���x��
	int _hazardLevel;
	// �\���J�E���^�[
	int _runawayCount;
	// �ő�\���J�E���^�[
	int _maxRunawayCount;
};

