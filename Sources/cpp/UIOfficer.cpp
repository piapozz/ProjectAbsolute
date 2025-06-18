#include "../header/UIOfficer.h"
#include "../header/ObjectFactory.h"

void UIOfficer::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// 初期化
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform(BACKGROUND_POS, BACKGROUND_SIZE, this);
	_pBackground = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	// 名前
	trans = Transform(NAME_POS, NAME_SIZE, this);
	_pOfficerName = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	// 画像
	trans = Transform(IMAGE_POS, IMAGE_SIZE, this);
	_pOfficerImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	// 武器
	trans = Transform(WEAPON_POS, WEAPON_SIZE, this);
	_pWeapon = ObjectFactory::Instance().CreateWithArgs<UIWeapon>(trans, fill, setLayer);
	// スーツ
	trans = Transform(SUIT_POS, SUIT_SIZE, this);
	_pSuit = ObjectFactory::Instance().CreateWithArgs<UISuit>(trans, fill, setLayer);
	// パラメータ
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
		trans = Transform(PARAM_POS[i], PARAM_SIZE[i], this);
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

void UIOfficer::SetOfficer(BaseOfficer& officer)
{
	_pOfficerName->SetText(officer.GetName());
	//_pOfficerImage->SetImage(officer.GetImagePath());
	_pWeapon->SetWeapon(*officer.GetWeapon());
	_pSuit->SetSuit(*officer.GetSuit());
	for (int i = 0; i < (int)Type::MAX; ++i)
	{
		//_pOfficerParam[i]->SetParam(officer.Get((Type)i));
	}
}