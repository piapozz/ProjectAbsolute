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
 * ���e��
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
	/// ��Ƃ��J�n����
	/// </summary>
	void StartOperation();
	/// <summary>
	/// �����g�_�E���̊J�n
	/// </summary>
	void StartMeltdown();
	/// <summary>
	/// �G���e�B�e�B�̊��蓖��
	/// </summary>
	/// <param name="pEntity"></param>
	void SetEntity(BaseEntity* pEntity);
	/// <summary>
	/// �C���^���N�g����E���̊��蓖��
	/// </summary>
	/// <param name="officerID"></param>
	inline void SetInteractOfficer(OfficerPlayer* setOfficer){ _pInteractOfficer = setOfficer; }
	inline bool CanMeltdown(){ return _currentState != State::INTERACT; }

private:
	// �����g�_�E���̃J�E���g��
	int _MELTDOWN_COUNT = 60 * 60;
	// ���e���Ă���G���e�B�e�B�[
	BaseEntity* _pEntity;
	bool _isMeltdown;
	int _meltdownCount;
	// ���
	BaseOperation* _pOperationList[(int)Type::MAX];
	// �C���^���N�g���̐E��
	OfficerPlayer* _pInteractOfficer;
	// ���݂̃X�e�[�g
	State _currentState;
	// �I�����ꂽ���
	Type _selectOperation;
	// ��Ƃ̖��O
	std::string _operationNameList[(int)Type::MAX];
	// UI
	UIButton* _pOperationUIList[(int)Type::MAX];
	UIButton* _pOperationCountUI;
	UIButton* _pRunawayCountUI;
	// UI�̃I�t�Z�b�g
	Vector2 _operationUIOffsetList[(int)Type::MAX];
	Vector2 _operationCountOffset;
	Vector2 _runawayCountOffset;

	/// <summary>
	/// �����g�_�E���̃J�E���g������
	/// </summary>
	void MeltdownProc();
	/// <summary>
	/// ��Ƃ̏���
	/// </summary>
	void OperationProc();
};

