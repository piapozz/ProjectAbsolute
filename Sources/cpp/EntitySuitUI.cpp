#include "../header/EntitySuitUI.h"

EntitySuitUI::EntitySuitUI(Transform setTransform, LayerSetting layerSetting, std::string tipsText)
	: BaseObject(setTransform, layerSetting)
{

}

void EntitySuitUI::SetActive(bool active)
{
	_lockText->SetActive(active);
	_information->SetActive(active);
	_image->SetActive(active);
	_rank->SetActive(active);
	_name->SetActive(active);
	_typeInformtaion->SetActive(active);
	_type->SetActive(active);
	_damageInformation->SetActive(active);
	_damage->SetActive(active);
	_speedInformation->SetActive(active);
	_speed->SetActive(active);
	_rangeInformation->SetActive(active);
	_range->SetActive(active);
}

void EntitySuitUI::Draw()
{
	_lockText->Draw();
	_information->Draw();
	_image->Draw();
	_rank->Draw();
	_name->Draw();
	_typeInformtaion->Draw();
	_type->Draw();
	_damageInformation->Draw();
	_damage->Draw();
	_speedInformation->Draw();
	_speed->Draw();
	_rangeInformation->Draw();
	_range->Draw();
}