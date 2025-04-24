#include "../header/EventManager.h"
#include "../header//StageManager.h"

void EventManager::Init()
{
	_energy = 0;
	_melt = 0;
	_pEnergySlider = new UISlider();
	_pEnergySlider->Init(Vector2(-100, 100), Vector2(500, 50));
	_pEnergySlider->SetLayer(Layer::NONE_INTERACT);
	_pEnergySlider->SetValue(_energy);
	_pEnergySlider->SetColor(0, 255, 0);
}

void EventManager::AddEnergy(int value)
{
	// エネルギーを追加
	_energy += value;
	if (_energy > _MAX_ENERGY) _energy = _MAX_ENERGY;
	if (_energy < 0) _energy = 0;
	// スライダーの更新
	_pEnergySlider->SetValue(_energy / _MAX_ENERGY);
	_pEnergySlider->SetText(std::to_string(_energy) + "/" + std::to_string(_MAX_ENERGY));
}

void EventManager::AddMelt()
{
	_melt++;
	// 最大になったら
	if (_melt < _MELT_MAX) return;
	_melt = 0;
	// 暴走を起こす
	StageManager::_secureRoomList[0]->StartMeltdown();
}