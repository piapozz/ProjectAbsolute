#pragma once
#include "UIScreenSlider.h"
#include "UIScreenButton.h"
/*
* ishihara
* �C�x���g�Ǘ�
*/
class EventManager
{
public:
	void Init();
	/// <summary>
	/// �G�l���M�[�̒ǉ�
	/// </summary>
	/// <param name="value"></param>
	void AddEnergy(int value);
	/// <summary>
	/// �����g�J�E���^�[�̒ǉ�
	/// </summary>
	void AddMelt();
private:
	// �G�l���M�[�ő�l
	const int _MAX_ENERGY = 100;
	// �����g�_�E���ő�l
	const int _MELT_MAX = 2;
	// �\�����x���ő�l
	const int _MELT_LEVEL_MAX = 10;
	// �G�l���M�[
	int _energy;
	// �����g�_�E���J�E���^�[
	int _melt;
	// �\�����x��
	int meltLevel;
	// �i���X���C�_�[
	UIScreenSlider* _pEnergySlider;
	// ��~�{�^��
	UIScreenButton* _pStopButton;
	// �ʏ�Đ��{�^��
	UIScreenButton* _pNormalSpeedButton;
	// �{���Đ��{�^��
	UIScreenButton* _pFastSpeedButton;
};