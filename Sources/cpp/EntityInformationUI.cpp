#include "../header/EntityInformationUI.h"
#include "../header/UIScreen.h"

EntityInformationUI::EntityInformationUI(Transform setTransform, LayerSetting layerSetting)
	: BaseObject(setTransform, layerSetting)
{

}

void EntityInformationUI::Draw()
{
	 _lockImage->Draw();
	 _informationFrame->Draw();
	 _information->Draw();
	 _image->Draw();
	 _name->Draw();
	 _id->Draw();
	 _hazardLevel->Draw();
	 _typeInformation->Draw();
	 _type->Draw();
	 _energyInformation->Draw();
	 _energy->Draw();
	 _operationInformation->Draw();
	 _goodOperationInformation->Draw();
	 _goodOperation->Draw();
	 _normalOperationInformation->Draw();
	 _normalOperation->Draw();
	 _badOperationInformation->Draw();
	 _badOperation->Draw();
}

void EntityInformationUI::SetActive(bool active)
{
	// 全InformationUIのアクティブを切り替える

}

