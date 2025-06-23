#include "../header/UISuit.h"
#include "../header/ObjectFactory.h"
#include <iomanip> 
#include <sstream>

void UISuit::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// èâä˙âª
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform(BACKGROUND_POS, BACKGROUND_SIZE, this);
	_pBackground = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	trans = Transform(NAME_POS, NAME_SIZE, this);
	_pSuitName = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	trans = Transform(RANK_POS, RANK_SIZE, this);
	_pSuitRank = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
		trans = Transform(DEFENSE_POS[i], DEFENSE_SIZE[i], this);
		_pSuitDefense[i] = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	}
}

void UISuit::Proc()
{
	if (_pBackground != nullptr) _pBackground->Proc();
	if (_pSuitName != nullptr) _pSuitName->Proc();
	if (_pSuitRank != nullptr) _pSuitRank->Proc();
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
		if (_pSuitDefense[i] != nullptr) _pSuitDefense[i]->Proc();
	}
	BaseUIScreen::Proc();
}

void UISuit::Draw()
{
	if (_pBackground != nullptr) _pBackground->Draw();
	if (_pSuitName != nullptr) _pSuitName->Draw();
	if (_pSuitRank != nullptr) _pSuitRank->Draw();
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
		if (_pSuitDefense[i] != nullptr) _pSuitDefense[i]->Draw();
	}
	BaseUIScreen::Draw();
}

void UISuit::Teardown()
{

}

void UISuit::SetSuit(BaseSuit* setSuit)
{
	_pSuitName->SetText(setSuit->GetName());
	//_pSuitRank->SetText(setSuit.GetRankString());
	float* defense = setSuit->GetMultipliers();
	for (int i = 0; i < static_cast<int>(Type::MAX); ++i)
	{
		if (_pSuitDefense[i])
		{
			float value = defense[i];
			std::ostringstream oss;
			if (std::abs(value - static_cast<int>(value)) < 0.01f)
			{
				oss << static_cast<int>(value);
			} else
			{
				oss << std::fixed << std::setprecision(1) << value;
			}
			Type type = (Type)i;
			_pSuitDefense[i]->SetText(oss.str());
			_pSuitDefense[i]->SetTextColor(ToColor(type));
		}
	}
}