#include "../header/EntityEscapeUI.h"

EntityEscapeUI::EntityEscapeUI(Transform setTransform, LayerSetting layerSetting, std::string tipsText)
	: BaseObject(setTransform, layerSetting)
{

}

void EntityEscapeUI::SetActive(bool active)
{
	_lockText->SetActive(active);
	_escapeInformation->SetActive(active);
	_runawayCountInformation->SetActive(active);
	_runawayCount->SetActive(active);
	_defenceInformation->SetActive(active);
	_redDefence->SetActive(active);
	_whiteDefence->SetActive(active);
	_blackDefence->SetActive(active);
	_blueDefence->SetActive(active);
}

void EntityEscapeUI::Draw()
{
	_lockText->Draw();
	_escapeInformation->Draw();
	_runawayCountInformation->Draw();
	_runawayCount->Draw();
	_defenceInformation->Draw();
	_redDefence->Draw();
	_whiteDefence->Draw();
	_blackDefence->Draw();
	_blueDefence->Draw();
}