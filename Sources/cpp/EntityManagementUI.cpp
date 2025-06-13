#include "../header/EntityManagementUI.h"
#include "../header/EntityManagementTipsUI.h"

EntityManagementUI::EntityManagementUI(Transform setTransform, LayerSetting layerSetting)
	: BaseObject(setTransform, layerSetting)
{

}

void EntityManagementUI::Draw()
{
	// ŠÇ—•û–@‚ğã‚©‚ç‡‚É•\¦
	for (int i = 0, max = _tipsUIList.size(); i < max; i++)
	{
		_tipsUIList[i]->Draw();
	}
}

void EntityManagementUI::SetActive(bool active)
{
	_informationText->Draw();

	for (int i = 0, max = _tipsUIList.size(); i < max; i++)
	{
		_tipsUIList[i]->SetActive(active);
	}
}