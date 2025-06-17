#include "../header/UIWeapon.h"
#include "../header/ObjectFactory.h"

void UIWeapon::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// èâä˙âª
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform(BACKGROUND_POS, BACKGROUND_SIZE, this);
	_pBackground = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	trans = Transform(NAME_POS, NAME_SIZE, this);
	_pWeaponName = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	trans = Transform(RANK_POS, RANK_SIZE, this);
	_pWeaponRank = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	trans = Transform(TYPE_POS, TYPE_SIZE, this);
	_pWeaponType = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	trans = Transform(ATTACK_POS, ATTACK_SIZE, this);
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