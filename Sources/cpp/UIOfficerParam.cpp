#include "../header/UIOfficerParam.h"
#include "../header/ObjectFactory.h"

void UIOfficerParam::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// èâä˙âª
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform();
	trans.parent = this;
	_pBackground = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	_pParamName = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	 _pParamValue = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
}

void UIOfficerParam::Proc()
{
	if (_pBackground != nullptr) _pBackground->Proc();
	if (_pParamName != nullptr) _pParamName->Proc();
	if (_pParamValue != nullptr) _pParamValue->Proc();
	BaseUIScreen::Proc();
}

void UIOfficerParam::Draw()
{
	if (_pBackground != nullptr) _pBackground->Draw();
	if (_pParamName != nullptr) _pParamName->Draw();
	if (_pParamValue != nullptr) _pParamValue->Draw();
	BaseUIScreen::Draw();
}

void UIOfficerParam::Teardown()
{

}