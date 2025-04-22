#pragma once
#include "../header/BaseCharacter.h"
class UIButton;

/*
 * Sakakura
 * エンティティーの基底
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
	/// 作業開始時イベント
	/// </summary>
	virtual void StartOperationEvent(){}
	/// <summary>
	/// 作業終了時イベント
	/// </summary>
	/// <param name="successCount"></param>
	virtual void EndOperationEvent(int successCount){}
	/// <summary>
	/// ツールか否か
	/// </summary>
	virtual bool IsTool() = 0;
	inline void SetOperation(Type setOperation){ _currentOperationType = setOperation; }
	void SetRunawayUI(UIButton* setUI);

protected:
	// マスターID
	int masterID;
	// 危険レベル
	int hazardLevel;
	// 暴走カウンター
	int runawayCount;
	// 最大暴走カウンター
	int maxRunawayCount;
	Type _currentOperationType;
	UIButton* _pRunawayUI;
};

