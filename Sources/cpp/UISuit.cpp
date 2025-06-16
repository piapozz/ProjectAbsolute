#include "../header/UISuit.h"
#include "../header/ObjectFactory.h"

void UISuit::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// èâä˙âª
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform();
	trans.parent = this;
	_pBackground = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	_pSuitName = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	_pSuitRank = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
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