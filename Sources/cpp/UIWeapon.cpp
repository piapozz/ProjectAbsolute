#include "../header/UIWeapon.h"
#include "../header/ObjectFactory.h"

void UIWeapon::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// èâä˙âª
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform();
	trans.parent = this;
	_pBackground = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	_pWeaponName = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	_pWeaponRank = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	_pWeaponType = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	_pWeaponAttack = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
}

void UIWeapon::Proc()
{
	if (_pBackground != nullptr) _pBackground->Proc();
	if (_pWeaponName != nullptr) _pWeaponName->Proc();
	if (_pWeaponRank != nullptr) _pWeaponRank->Proc();
	if (_pWeaponType != nullptr) _pWeaponType->Proc();
	if (_pWeaponAttack != nullptr) _pWeaponAttack->Proc();
	BaseUIScreen::Proc();
}

void UIWeapon::Draw()
{
	if (_pBackground != nullptr) _pBackground->Draw();
	if (_pWeaponName != nullptr) _pWeaponName->Draw();
	if (_pWeaponRank != nullptr) _pWeaponRank->Draw();
	if (_pWeaponType != nullptr) _pWeaponType->Draw();
	if (_pWeaponAttack != nullptr) _pWeaponAttack->Draw();
	BaseUIScreen::Draw();
}

void UIWeapon::Teardown()
{

}