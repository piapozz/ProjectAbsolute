#include "../header/EntityEscapeUI.h"
#include "../header/ObjectFactory.h"

EntityEscapeUI::EntityEscapeUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);

	ObjectFactory& factory = ObjectFactory::Instance();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	Transform worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
}

void EntityEscapeUI::SetActive(bool active)
{
	_BGImage->SetActive(active);
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
	_BGImage->Draw();
	//_lockText->Draw();
	//_escapeInformation->Draw();
	//_runawayCountInformation->Draw();
	//_runawayCount->Draw();
	//_defenceInformation->Draw();
	//_redDefence->Draw();
	//_whiteDefence->Draw();
	//_blackDefence->Draw();
	//_blueDefence->Draw();
}