#include "../header/EventManager.h"
#include "../header//StageManager.h"
#include "../header/ObjectManager.h"
#include "../header/ObjectFactory.h"
#include "../header/UIButton.h"
#include<random>

void EventManager::Init()
{
	_energy = 0;
	_melt = 0;
	meltLevel = 0;
	_maxEnergy = std::round((float)(_ADD_ENERGY * _GetDay()) * _FACTOR_ENERGY);

	ObjectFactory& factory = ObjectFactory::Instance();
	LayerSetting layerSetting = {true, false, Layer::BACK};
	Transform transform = Transform(Vector2(400, 100), Vector2(500, 50));
	_pEnergySlider = factory.CreateWithArgs<UIScreenSlider>(transform, true, layerSetting);
	_pEnergySlider->SetValue(_energy);
	_pEnergySlider->SetColor(0, 255, 0);
	std::string str = std::to_string(_energy) + "/" + std::to_string(_maxEnergy);
	_pEnergySlider->SetText(str.c_str());

	transform = Transform(Vector2(400, 150), Vector2(500, 50));
	_pMeltSlider = factory.CreateWithArgs<UIScreenSlider>(transform, true, layerSetting);
	_pMeltSlider->SetValue(_melt);
	_pMeltSlider->SetColor(255, 0, 0);
	str = std::to_string(_melt) + "/" + std::to_string(_MELT_MAX);
	_pMeltSlider->SetText(str.c_str());

	layerSetting = {true, true, Layer::BACK};
	// 停止ボタン
	transform = Transform(Vector2(100, 1050), Vector2(200, 50));
	_pStopButton = factory.CreateWithArgs<UIScreenButton>(transform, true, layerSetting);
	_pStopButton->SetText("停止");
	_pStopButton->SetCallback([this]()
	{
		// 停止ボタンが押されたときの処理
		ObjectManager::Instance().ChangeGameSpeed(0);
	});
	// 通常速度ボタン
	transform = Transform(Vector2(300, 1050), Vector2(200, 50));
	_pNormalSpeedButton = factory.CreateWithArgs<UIScreenButton>(transform, true, layerSetting);
	_pNormalSpeedButton->SetText("通常");
	_pNormalSpeedButton->SetCallback([this]()
	{
		// 通常速度ボタンが押されたときの処理
		ObjectManager::Instance().ChangeGameSpeed(1);
	});
	// 倍速ボタン
	transform = Transform(Vector2(500, 1050), Vector2(200, 50));
	_pFastSpeedButton = factory.CreateWithArgs<UIScreenButton>(transform, true, layerSetting);
	_pFastSpeedButton->SetText("倍速");
	_pFastSpeedButton->SetCallback([this]()
	{
		// 倍速ボタンが押されたときの処理
		ObjectManager::Instance().ChangeGameSpeed(8);
	});
}

void EventManager::AddEnergy(int value)
{
	// エネルギーを追加
	_energy += value;
	if (_energy > _maxEnergy)
	{
		_energy = _maxEnergy;
	}
	if (_energy < 0) _energy = 0;
	// スライダーの更新
	_pEnergySlider->SetValue(static_cast<float>(_energy) / static_cast<float>(_maxEnergy));
	_pEnergySlider->SetText((std::to_string(_energy) + "/" + std::to_string(_maxEnergy)).c_str());

	// エネルギーがマックスならリザルトUIを表示
	if (IsMaxEnergy())
		_DisplayContinueResult();
}

void EventManager::AddMelt()
{
	_melt++;
	// スライダーの更新
	_pMeltSlider->SetValue(static_cast<float>(_melt) / static_cast<float>(_MELT_MAX));
	_pMeltSlider->SetText((std::to_string(_melt) + "/" + std::to_string(_MELT_MAX)).c_str());

	if (_melt < _MELT_MAX) return;

	_melt = 0;
	meltLevel++;
	_pMeltSlider->SetValue(static_cast<float>(_melt) / static_cast<float>(_MELT_MAX));
	_pMeltSlider->SetText((std::to_string(_melt) + "/" + std::to_string(_MELT_MAX)).c_str());

	// 暴走可能なSecureRoomだけを抽出
	std::vector<SecureRoom*> meltableRooms;
	std::vector<SecureRoom*> secureRoomList = StageManager::Instance().GetSecureRoom(0);
	for (SecureRoom* room : secureRoomList)
	{
		if (room->CanMeltdown()) 
		{
			meltableRooms.push_back(room);
		}
	}
	// 暴走対象の数を計算
	int meltCount = std::min<int>(
		std::ceil(meltableRooms.size() * static_cast<float>(meltLevel) / static_cast<float>(_MELT_LEVEL_MAX)),
		meltableRooms.size()
	);
	// ランダムにmeltCount個選出して暴走させる
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(meltableRooms.begin(), meltableRooms.end(), gen);
	for (int i = 0; i < meltCount; ++i)
	{
		meltableRooms[i]->StartMeltdown();
	}
}
