#pragma once
#include "../header/BaseCharacter.h"

/*
 * Sakakura
 * エンティティーの基底
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
	/// 暴走カウンターを減少させる
	/// </summary>
	void DecreaseRunawayCount();
	/// <summary>
	/// 暴走カウンターのセット
	/// </summary>
	/// <param name="count"></param>
	inline void SetRunawayCount(int count){ _runawayCount = count; }
	// 作業開始時、作業終了時、クリフォトカウンター減少時などの関数
	// 特定の収容室の前を通過した場合
	// 特定人数が死亡した時
	
	/// <summary>
	/// 作業開始時イベント
	/// </summary>
	virtual void StartOperationEvent(){};
	/// <summary>
	/// 作業終了時イベント
	/// </summary>
	/// <param name="successCount"></param>
	virtual void EndOperationEvent(int successCount){};
	/// <summary>
	/// 暴走イベント
	/// </summary>
	virtual void RunawayEvent(){};
	virtual void IsTool() = 0;

protected:

private:
	int _ID;
	// 危険レベル
	int _hazardLevel;
	// 暴走カウンター
	int _runawayCount;
	// 最大暴走カウンター
	int _maxRunawayCount;
};

