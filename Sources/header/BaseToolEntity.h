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

	void Init();
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
	inline bool IsTool() override { return true; }

private:
	// ツールの種類
	ToolType _toolType;

	/// <summary>
	/// 使用中の処理
	/// </summary>
	virtual void UseProc(){}
	/// <summary>
	/// 使用開始時のイベント
	/// </summary>
	/// <param name="userID"></param>
	virtual void UseEvent(){}
	/// <summary>
	/// 使用中止時のイベント
	/// </summary>
	virtual void DisuseEvent(){}
};

