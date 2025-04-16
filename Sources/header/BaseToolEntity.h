#pragma once
#include "../header/BaseEntity.h"
class BaseToolEntity: public BaseEntity
{
public:
	BaseToolEntity(){}
	~BaseToolEntity(){}

	/// <summary>
	/// �g�p����
	/// </summary>
	/// <param name="officerID"></param>
	void Use(int officerID);
	/// <summary>
	/// �g�p����߂�
	/// </summary>
	void Disuse();
	/// <summary>
	/// �g�p���̏���
	/// </summary>
	virtual void UseProc(){}

private:
	enum class Type
	{
		Single = 0,
		Continue,
		Equip,
	};
	int _useOfficerID;
};

