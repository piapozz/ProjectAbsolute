#pragma once
#include "UISlider.h"
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
	// �G�l���M�[
	int _energy;
	// �����g�_�E���ő�l
	const int _MELT_MAX = 2;
	// �����g�_�E���J�E���^�[
	int _melt;
	// �X���C�_�[
	UISlider* _pEnergySlider;
};

