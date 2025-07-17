#pragma once
#include <vector>
#include <string>
#include "functional"
#include "../header/Const.h"
#include "../header/BaseSection.h"
class BaseEntity;
class BaseOperation;
class OfficerPlayer;
class UIButton;
class UIScreenButton;
class UIEntity;
class UIText;
class SelectOperationUI;

/*
 * Sakakura
 * 収容室
 */
class SecureRoom: public BaseSection
{
public:
	// 作業開始時のコールバック
	static std::function<void()> StartOperationEvent;
	// 作業終了時のコールバック
	static std::function<void(int)> EndOperationEvent;
	// 表示するUIを取得するコールバック
	static std::function<UIEntity*(void)> GetUIEntityCallback;
	static std::function<SelectOperationUI*(void)> GetUIOperationCallback;

	static std::string StaticTypeName() {
		return "SecureRoom";
	}

	enum class State
	{
		IDLE = 0,
		SELECT,
		INTERACT,
		RUNAWAY
	};
	SecureRoom(){
	};
	SecureRoom(Transform setTransform, LayerSetting layerSetting)
		:_isMeltdown(false), _meltdownCount(0){ Init(setTransform, layerSetting); };
	SecureRoom(BaseEntity* pEntity)
		:_pEntity(pEntity), _isMeltdown(false), _meltdownCount(0){}
	~SecureRoom(){ Teardown(); }

	void Init(Transform setTransform, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override;
	/// <summary>
	/// 作業を開始する
	/// </summary>
	void StartOperation();
	/// <summary>
	/// メルトダウンの開始
	/// </summary>
	void StartMeltdown();
	/// <summary>
	/// エンティティの割り当て
	/// </summary>
	/// <param name="pEntity"></param>
	void SetEntity(BaseEntity* pEntity);
	/// <summary>
	/// インタラクトする職員の割り当て
	/// </summary>
	/// <param name="officerID"></param>
	inline void SetInteractOfficer(OfficerPlayer* setOfficer){ _pInteractOfficer = setOfficer; }
	inline bool CanMeltdown(){ return !_isMeltdown && _pEntity != nullptr; }
	inline void SetState(State state){ _currentState = state; }
	inline void SetDivisionIndex(int index){ _divisionIndex = index; }

private:
	// メルトダウンのカウント数
	const int _MELTDOWN_COUNT = 60 * 60;
	// エンティティのオフセット
	const Vector2 _ENTITY_OFFSET = Vector2(-0.5f, -0.5f);
	// 職員のオフセット
	const Vector2 _OFFICER_OFFSET = Vector2(0.5f, -1.0f);
	// カウントUI
	const Vector2 _MELTDOWN_COUNT_UI_POS = Vector2(-0.9f, 0.8f);
	const Vector2 _OPERATION__COUNT_UI_POS = Vector2(0.9f, 0.8f);
	const Vector2 _COUNT_UI_SCALE = Vector2(0.1f, 0.2f);
	const int _COUNT_UI_FONT_SIZE = 10;
	// 名前UI
	const Vector2 _NAME_UI_POS = Vector2(0, 0.8f);
	const Vector2 _NAME_UI_SCALE = Vector2(0.8f, 0.2f);

	// 収容しているエンティティー
	BaseEntity* _pEntity;
	bool _isMeltdown;
	int _meltdownCount;
	// 配属された区画
	int _divisionIndex;
	// 作業
	BaseOperation* _pOperationList[(int)Type::MAX];
	// インタラクト中の職員
	OfficerPlayer* _pInteractOfficer;
	// 現在のステート
	State _currentState;
	// 選択された作業
	Type _selectOperation;
	// 作業の名前
	std::string _operationNameList[(int)Type::MAX];
	// UI
	UIButton* _pOperationCountUI;
	UIButton* _pRunawayCountUI;
	UIButton* _pInformationUI;
	UIEntity* _pEntityUI;
	UIText* _pMeltText;

	/// <summary>
	/// メルトダウンのカウントをする
	/// </summary>
	void MeltdownProc();
	/// <summary>
	/// 作業の処理
	/// </summary>
	void OperationProc();
	/// <summary>
	/// エンティティの再配置
	/// </summary>
	void ReplaceEntity();
};

