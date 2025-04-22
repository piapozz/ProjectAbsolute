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

/*
 * Sakakura
 * 収容室
 */
class SecureRoom: public BaseSection
{
public:
	static std::function<void(int)> EndOperation;
	static inline void SetEndOperationCallback(std::function<void(int)> setCallback){ EndOperation = setCallback; }

	enum class State
	{
		IDLE = 0,
		INTERACT,
		RUNAWAY
	};

	SecureRoom()
		:_isMeltdown(false), _meltdownCount(0){};
	SecureRoom(BaseEntity* pEntity)
		:_pEntity(pEntity), _isMeltdown(false), _meltdownCount(0){}
	~SecureRoom(){ Teardown(); }

	void Init(Vector2 position, Vector2 size) override;
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

private:
	// メルトダウンのカウント数
	int _MELTDOWN_COUNT = 60 * 60;
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
	UIButton* _pOperationUIList[(int)Type::MAX];
	UIButton* _pOperationCountUI;
	UIButton* _pRunawayCountUI;
	// UIのオフセット
	Vector2 _operationUIOffsetList[(int)Type::MAX];
	Vector2 _operationCountOffset;
	Vector2 _runawayCountOffset;

	/// <summary>
	/// メルトダウンのカウントをする
	/// </summary>
	void MeltdownProc();
	/// <summary>
	/// 作業の処理
	/// </summary>
	void OperationProc();
};

