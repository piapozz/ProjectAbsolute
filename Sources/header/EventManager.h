#pragma once
#include "UISlider.h"
/*
* ishihara
* ƒCƒxƒ“ƒgŠÇ—
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

