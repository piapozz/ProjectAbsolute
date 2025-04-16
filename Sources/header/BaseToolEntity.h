#pragma once
#include "../header/BaseEntity.h"

/*
 * Sakakura
 * ツール型エンティティーの基底
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

	void Proc() override;

	/// <summary>
	/// 使用する
	/// </summary>
	/// <param name="officerID"></param>
	void Use(int userID);
	/// <summary>
	/// 使用をやめる
	/// </summary>
	void Disuse();
	/// <summary>
	/// 使用中の処理
	/// </summary>
	virtual void UseProc(){}
	/// <summary>
	/// 使用開始時のイベント
	/// </summary>
	/// <param name="userID"></param>
	virtual void UseEvent(int userID){};
	/// <summary>
	/// 使用中止時のイベント
	/// </summary>
	virtual void DisuseEvent(int userID){}
	inline bool IsTool() override { return true; }
	inline bool CanMeltdown() override { return interactOfficerID < 0; }

private:
	// ツールの種類
	ToolType _toolType;
};

