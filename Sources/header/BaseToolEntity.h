#pragma once
#include "../header/BaseEntity.h"
class BaseToolEntity: public BaseEntity
{
public:
	BaseToolEntity(){}
	~BaseToolEntity(){}

	/// <summary>
	/// 使用する
	/// </summary>
	/// <param name="officerID"></param>
	void Use(int officerID);
	/// <summary>
	/// 使用をやめる
	/// </summary>
	void Disuse();
	/// <summary>
	/// 使用中の処理
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

