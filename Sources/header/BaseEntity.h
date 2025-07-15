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
	BaseEntity(LayerSetting layerSetting){
		Init(layerSetting);
	}
	BaseEntity(int ID)
		:masterID(ID){}
	virtual ~BaseEntity(){}

	void Init(LayerSetting layerSetting) override;
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
	inline void SetOperation(Type setOperation){ currentOperationType = setOperation; }
	void SetRunawayUI(UIButton* setUI);
	inline void SetManagementData(EntityManagementData setData){ managementData = setData; }
	inline EntityManagementData GetManagementData(){ return managementData; }
	inline void SetRunawayCallback(std::function<void()> setCallback){ RunawayCallback = setCallback; }

protected:
	// マスターID
	int masterID;
	// 管理データ
	EntityManagementData managementData;
	// 危険レベル
	int hazardLevel;
	// 暴走カウンター
	int runawayCount;
	// 最大暴走カウンター
	int maxRunawayCount;
	Type currentOperationType;
	UIButton* pRunawayUI;
	std::function<void()> RunawayCallback;
};

