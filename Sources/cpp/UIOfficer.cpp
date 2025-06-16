#include "../header/UIOfficer.h"
#include "../header/ObjectFactory.h"

void UIOfficer::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// èâä˙âª
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform();
	trans.parent = this;
	_pBackground = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	_pOfficerName = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	_pOfficerImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	_pWeapon = ObjectFactory::Instance().CreateWithArgs<UIWeapon>(trans, fill, setLayer);
	_pSuit = ObjectFactory::Instance().CreateWithArgs<UISuit>(trans, fill, setLayer);
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
		_pOfficerParam[i] = ObjectFactory::Instance().CreateWithArgs<UIOfficerParam>(trans, fill, setLayer);
	}
}

void UIOfficer::Proc()
{
	if (_pBackground != nullptr) _pBackground->Proc();
	if (_pOfficerName != nullptr) _pOfficerName->Proc();
	if (_pOfficerImage != nullptr) _pOfficerImage->Proc();
	if (_pWeapon != nullptr) _pWeapon->Proc();
	if (_pSuit != nullptr) _pSuit->Proc();
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
		if (_pOfficerParam[i] != nullptr) _pOfficerParam[i]->Proc();
	}
	BaseUIScreen::Proc();
}

void UIOfficer::Draw()
{
	if (_pBackground != nullptr) _pBackground->Draw();
	if (_pOfficerName != nullptr) _pOfficerName->Draw();
	if (_pOfficerImage != nullptr) _pOfficerImage->Draw();
	if (_pWeapon != nullptr) _pWeapon->Draw();
	if (_pSuit != nullptr) _pSuit->Draw();
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
		if (_pOfficerParam[i] != nullptr) _pOfficerParam[i]->Draw();
	}
	BaseUIScreen::Draw();
}

void UIOfficer::Teardown()
{

}

void UIOfficer::SetOfficer(BaseOfficer officer)
{

}