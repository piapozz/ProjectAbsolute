#include "../header/EventManager.h"
#include "../header//StageManager.h"
#include<random>

void EventManager::Init()
{
	_energy = 0;
	_melt = 0;
	meltLevel = 1;
	_pEnergySlider = new UIScreenSlider();
	_pEnergySlider->Init(Vector2(400, 100), Vector2(500, 50));
	_pEnergySlider->SetLayer(Layer::NONE_INTERACT);
	_pEnergySlider->SetValue(_energy);
	_pEnergySlider->SetColor(0, 255, 0);
	std::string str = std::to_string(_energy) + "/" + std::to_string(_MAX_ENERGY);
	_pEnergySlider->SetText(str.c_str());
	_pEnergySlider->SetTextColor();
}

void EventManager::AddEnergy(int value)
{
	// エネルギーを追加
	_energy += value;
	if (_energy > _MAX_ENERGY) _energy = _MAX_ENERGY;
	if (_energy < 0) _energy = 0;
	// スライダーの更新
	_pEnergySlider->SetValue(_energy / _MAX_ENERGY);
	_pEnergySlider->SetText((std::to_string(_energy) + "/" + std::to_string(_MAX_ENERGY)).c_str());
}

void EventManager::AddMelt()
{
	_melt++;

	// 暴走可能なSecureRoomだけを抽出
	std::vector<SecureRoom*> meltableRooms;
	for (SecureRoom* room : StageManager::_secureRoomList) 
	{
		if (room->CanMeltdown()) 
		{
			meltableRooms.push_back(room);
		}
	}
	// 暴走対象の数を計算
	int meltCount = std::min<int>(
		std::ceil(meltableRooms.size() * meltLevel / _MELT_LEVEL_MAX),
		meltableRooms.size()
	);
	if (_melt < meltCount) return;

	_melt = 0;
	meltLevel++;
	// ランダムにmeltCount個選出して暴走させる
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(meltableRooms.begin(), meltableRooms.end(), gen);
	for (int i = 0; i < meltCount; ++i)
	{
		meltableRooms[i]->StartMeltdown();
	}
}
