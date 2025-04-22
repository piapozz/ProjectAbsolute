#pragma once
#include "../header/BaseEntity.h"

/*
 * Sakakura
 * �c�[���^�G���e�B�e�B�[�̊��
 */
class BaseToolEntity: public BaseEntity
{
public:
	enum class ToolType
	{
		Single = 0,
		Continue,
		Equip,
	};
	BaseToolEntity(ToolType setType)
		:_toolType(setType){}
	~BaseToolEntity(){}

	void Init();
	void Proc() override;
	/// <summary>
	/// �g�p����
	/// </summary>
	/// <param name="officerID"></param>
	void Use(int userID);
	/// <summary>
	/// �g�p����߂�
	/// </summary>
	void Disuse();
	inline bool IsTool() override { return true; }

private:
	// �c�[���̎��
	ToolType _toolType;

	/// <summary>
	/// �g�p���̏���
	/// </summary>
	virtual void UseProc(){}
	/// <summary>
	/// �g�p�J�n���̃C�x���g
	/// </summary>
	/// <param name="userID"></param>
	virtual void UseEvent(){}
	/// <summary>
	/// �g�p���~���̃C�x���g
	/// </summary>
	virtual void DisuseEvent(){}
};

