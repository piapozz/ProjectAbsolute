#include "../header/EventManager.h"
#include "../header//StageManager.h"
#include "../header/ObjectManager.h"
#include "../header/UIButton.h"
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

	UIButton* _pEnergyButton = new UIButton();
	_pEnergyButton->Init(Vector2(100, 1050), Vector2(500, 50));
	_pEnergyButton->SetLayer(Layer::UI);
	_pEnergyButton->SetText("�G�l���M�[");
	_pEnergyButton->SetCallback([this]()
	{
		// �G�l���M�[�̕\��/��\���؂�ւ�
		if (_pEnergySlider->GetLayer() != Layer::NONE_DRAW)
		{
			_pEnergySlider->SetActive(false);
		} else
		{
			_pEnergySlider->SetActive(true);
		}
	});

	// ��~�{�^��
	_pStopButton = new UIScreenButton();
	_pStopButton->Init(Vector2(100, 1050), Vector2(200, 50));
	_pStopButton->SetLayer(Layer::UI);
	_pStopButton->SetText("��~");
	_pStopButton->SetCallback([this]()
	{
		// ��~�{�^���������ꂽ�Ƃ��̏���
		ObjectManager::instance->ChangeGameSpeed(0);
	});
	_pStopButton->SetTextColor();
	// �ʏ푬�x�{�^��
	_pNormalSpeedButton = new UIScreenButton();
	_pNormalSpeedButton->Init(Vector2(300, 1050), Vector2(200, 50));
	_pNormalSpeedButton->SetLayer(Layer::UI);
	_pNormalSpeedButton->SetText("�ʏ�");
	_pNormalSpeedButton->SetCallback([this]()
	{
		// �ʏ푬�x�{�^���������ꂽ�Ƃ��̏���
		ObjectManager::instance->ChangeGameSpeed(1);
	});
	_pNormalSpeedButton->SetTextColor();
	// �{���{�^��
	_pFastSpeedButton = new UIScreenButton();
	_pFastSpeedButton->Init(Vector2(500, 1050), Vector2(200, 50));
	_pFastSpeedButton->SetLayer(Layer::UI);
	_pFastSpeedButton->SetText("�{��");
	_pFastSpeedButton->SetCallback([this]()
	{
		// �{���{�^���������ꂽ�Ƃ��̏���
		ObjectManager::instance->ChangeGameSpeed(2);
	});
	_pFastSpeedButton->SetTextColor();
}

void EventManager::AddEnergy(int value)
{
	// �G�l���M�[��ǉ�
	_energy += value;
	if (_energy > _MAX_ENERGY) _energy = _MAX_ENERGY;
	if (_energy < 0) _energy = 0;
	// �X���C�_�[�̍X�V
	_pEnergySlider->SetValue(static_cast<float>(_energy) / static_cast<float>(_MAX_ENERGY));
	_pEnergySlider->SetText((std::to_string(_energy) + "/" + std::to_string(_MAX_ENERGY)).c_str());
}

void EventManager::AddMelt()
{
	_melt++;

	// �\���\��SecureRoom�����𒊏o
	std::vector<SecureRoom*> meltableRooms;
	for (SecureRoom* room : StageManager::_secureRoomList) 
	{
		if (room->CanMeltdown()) 
		{
			meltableRooms.push_back(room);
		}
	}
	// �\���Ώۂ̐����v�Z
	int meltCount = std::min<int>(
		std::ceil(meltableRooms.size() * meltLevel / _MELT_LEVEL_MAX),
		meltableRooms.size()
	);
	if (_melt < meltCount) return;

	_melt = 0;
	meltLevel++;
	// �����_����meltCount�I�o���Ė\��������
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(meltableRooms.begin(), meltableRooms.end(), gen);
	for (int i = 0; i < meltCount; ++i)
	{
		meltableRooms[i]->StartMeltdown();
	}
}
