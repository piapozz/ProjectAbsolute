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
	void AddEnergy(int value);
private:
	const int _MAX_ENERGY = 100;
	int _energy;
	UISlider* _pEnergySlider;
};

