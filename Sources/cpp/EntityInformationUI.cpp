#include "../header/ObjectFactory.h"
#include "../header/EntityInformationUI.h"
#include "../header/UIScreen.h"
#include "../header/UIText.h"

EntityInformationUI::EntityInformationUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);

	ObjectFactory& factory = ObjectFactory::Instance();

	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);
	Transform worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_lockImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	worldTransform = Transform(_INFORMATION_POS, Vector2::one(), this);
	layer = LayerSetting(true, false, Layer::BACK);
	_information = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_information->SetText("Entity Information");

	/*_informationFrame = new UIScreenImage();
	_information = new UIScreenText();
	_image = new UIScreenImage();
	_name = new UIScreenText();
	_id = new UIScreenText();
	_hazardLevel = new UIScreenText();
	_typeInformation = new UIScreenText();
	_type = new UIScreenText();
	_energyInformation = new UIScreenText();
	_energy = new UIScreenText();
	_operationInformation = new UIScreenText();
	_goodOperationInformation = new UIScreenText();
	_goodOperation = new UIScreenText();
	_normalOperationInformation = new UIScreenText();
	_normalOperation = new UIScreenText();
	_badOperationInformation = new UIScreenText();
	_badOperation = new UIScreenText();*/
}

void EntityInformationUI::Draw()
{
	 _lockImage->Draw();
	 //_information->Draw();
	 /*_informationFrame->Draw();
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
	 _badOperation->Draw();*/
}

void EntityInformationUI::SetActive(bool active)
{
	// 全InformationUIのアクティブを切り替える

}

