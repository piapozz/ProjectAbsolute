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

	enum class State
	{
		IDLE = 0,
		SELECT,
		INTERACT,
		RUNAWAY
	};
	SecureRoom(){
	};
	SecureRoom(Vector2 position, Vector2 size, LayerSetting layerSetting)
		:_isMeltdown(false), _meltdownCount(0){ Init(position, size, layerSetting); };
	SecureRoom(BaseEntity* pEntity)
		:_pEntity(pEntity), _isMeltdown(false), _meltdownCount(0){}
	~SecureRoom(){ Teardown(); }

	void Init(Vector2 position, Vector2 size, LayerSetting layerSetting) override;
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
	inline bool CanMeltdown(){ return _currentState != State::INTERACT; }
	inline static void SetGetUICallback(std::function<std::vector<OfficerPlayer*>()> Callback){ _GetUICallback = Callback; }
	inline void SetState(State state){ _currentState = state; }

private:
	// メルトダウンのカウント数
	const int _MELTDOWN_COUNT = 60 * 60;
	// エンティティのオフセット
	const float _ENTITY_OFFSET_POS_X = -SECTION_SIZE_X / 4;
	const float _ENTITY_OFFSET_POS_Y = -SECTION_SIZE_Y / 4;
	// 職員のオフセット
	const float _OFFICER_OFFSET_POS_X = SECTION_SIZE_X / 4;
	const float _OFFICER_OFFSET_POS_Y = -SECTION_SIZE_Y / 4;
	// UIのサイズ
	const float _COUNT_UI_SIZE = SECTION_SIZE_X / 10;
	const float _SCREEN_UI_SIZE_X = WINDOW_WIDTH / 6;
	const float _SCREEN_UI_SIZE_Y = WINDOW_HEIGHT / 3;

	// 収容しているエンティティー
	BaseEntity* _pEntity;
	bool _isMeltdown;
	int _meltdownCount;
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
	// UIのオフセット
	Vector2 _operationCountOffset;
	Vector2 _runawayCountOffset;
	// 表示するUIを取得するコールバック
	static std::function<std::vector<OfficerPlayer*>()> _GetUICallback;

	/// <summary>
	/// メルトダウンのカウントをする
	/// </summary>
	void MeltdownProc();
	/// <summary>
	/// 作業の処理
	/// </summary>
	void OperationProc();
};

