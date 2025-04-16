#pragma once
#include "../header/BaseCharacter.h"

/*
 * Sakakura
 * エンティティーの基底
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
	/// 暴走カウンターを減少させる
	/// </summary>
	void DecreaseRunawayCount();
	/// <summary>
	/// 暴走カウンターのセット
	/// </summary>
	/// <param name="count"></param>
	inline void SetRunawayCount(int count){ runawayCount = count; }
	/// <summary>
	/// 暴走イベント
	/// </summary>
	virtual void RunawayEvent(){};
	/// <summary>
	/// ツールか否か
	/// </summary>
	virtual bool IsTool() = 0;
	virtual bool CanMeltdown() = 0;

protected:
	// マスターID
	int masterID;
	// 危険レベル
	int hazardLevel;
	// 暴走カウンター
	int runawayCount;
	// 最大暴走カウンター
	int maxRunawayCount;
	// インタラクト中の職員ID
	int interactOfficerID;
};

