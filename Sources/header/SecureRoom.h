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
 * ���e��
 */
class SecureRoom: public BaseSection
{
public:
	// ��ƊJ�n���̃R�[���o�b�N
	static std::function<void()> StartOperationEvent;
	// ��ƏI�����̃R�[���o�b�N
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
	inline static void SetGetUICallback(std::function<std::vector<OfficerPlayer*>()> Callback){ _GetUICallback = Callback; }
	inline void SetState(State state){ _currentState = state; }

private:
	// �����g�_�E���̃J�E���g��
	const int _MELTDOWN_COUNT = 60 * 60;
	// �G���e�B�e�B�̃I�t�Z�b�g
	const float _ENTITY_OFFSET_POS_X = -SECTION_SIZE_X / 4;
	const float _ENTITY_OFFSET_POS_Y = -SECTION_SIZE_Y / 4;
	// �E���̃I�t�Z�b�g
	const float _OFFICER_OFFSET_POS_X = SECTION_SIZE_X / 4;
	const float _OFFICER_OFFSET_POS_Y = -SECTION_SIZE_Y / 4;
	// UI�̃T�C�Y
	const float _COUNT_UI_SIZE = SECTION_SIZE_X / 10;
	const float _SCREEN_UI_SIZE_X = WINDOW_WIDTH / 6;
	const float _SCREEN_UI_SIZE_Y = WINDOW_HEIGHT / 3;

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
	UIButton* _pOperationCountUI;
	UIButton* _pRunawayCountUI;
	// UI�̃I�t�Z�b�g
	Vector2 _operationCountOffset;
	Vector2 _runawayCountOffset;
	// �\������UI���擾����R�[���o�b�N
	static std::function<std::vector<OfficerPlayer*>()> _GetUICallback;

	/// <summary>
	/// �����g�_�E���̃J�E���g������
	/// </summary>
	void MeltdownProc();
	/// <summary>
	/// ��Ƃ̏���
	/// </summary>
	void OperationProc();
};

