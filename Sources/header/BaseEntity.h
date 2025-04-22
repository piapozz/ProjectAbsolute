#pragma once
#include "../header/BaseCharacter.h"
class UIButton;

/*
 * Sakakura
 * �G���e�B�e�B�[�̊��
 */
class BaseEntity: public BaseCharacter
{
public:
	BaseEntity(){}
	BaseEntity(int ID)
		:masterID(ID){}
	virtual ~BaseEntity(){}

	void Init() override;
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
	/// ��ƊJ�n���C�x���g
	/// </summary>
	virtual void StartOperationEvent(){}
	/// <summary>
	/// ��ƏI�����C�x���g
	/// </summary>
	/// <param name="successCount"></param>
	virtual void EndOperationEvent(int successCount){}
	/// <summary>
	/// �c�[�����ۂ�
	/// </summary>
	virtual bool IsTool() = 0;
	inline void SetOperation(Type setOperation){ _currentOperationType = setOperation; }
	void SetRunawayUI(UIButton* setUI);

protected:
	// �}�X�^�[ID
	int masterID;
	// �댯���x��
	int hazardLevel;
	// �\���J�E���^�[
	int runawayCount;
	// �ő�\���J�E���^�[
	int maxRunawayCount;
	Type _currentOperationType;
	UIButton* _pRunawayUI;
};

