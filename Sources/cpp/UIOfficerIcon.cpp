#include "../header/UIOfficerIcon.h"
#include "../header/ObjectFactory.h"
#include "../header/UIOfficerList.h"

std::function<void(UIOfficerIcon*)> UIOfficerIcon::startDrackCallback;
std::function<void(UIOfficerIcon*)> UIOfficerIcon::onDrackCallback;
std::function<void(UIOfficerIcon*)> UIOfficerIcon::endDrackCallback;

void UIOfficerIcon::Init(Transform setTrasnform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTrasnform, layerSetting);

	Transform trans = Transform(BACKGROUND_POS, BACKGROUND_SIZE, this);
	LayerSetting layer = {true, true, Layer::BACK};
	_backgroundImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, false, layer);
	// ƒ‰ƒ“ƒN
	trans = Transform(RANK_POS, RANK_SIZE, this);
	layer = {true, false, Layer::BACK};
	_officerRankText = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, layer);
	// –¼‘O
	trans = Transform(NAME_POS, NAME_SIZE, this);
	_officerNameText = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, layer);
	// ‰æ‘œ
	trans = Transform(IMAGE_POS, IMAGE_SIZE, this);
	_officerIconImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, false, layer);
}
void UIOfficerIcon::Proc()
{
	if (_backgroundImage != nullptr) _backgroundImage->Proc();
	if (_officerRankText != nullptr) _officerRankText->Proc();
	if (_officerNameText != nullptr) _officerNameText->Proc();
	if (_officerIconImage != nullptr) _officerIconImage->Proc();
	BaseUIScreen::Proc();
}
void UIOfficerIcon::Draw()
{
	if (_backgroundImage != nullptr) _backgroundImage->Draw();
	if (_officerRankText != nullptr) _officerRankText->Draw();
	if (_officerNameText != nullptr) _officerNameText->Draw();
	if (_officerIconImage != nullptr) _officerIconImage->Draw();
	BaseUIScreen::Draw();
}

void UIOfficerIcon::Teardown()
{

}

void UIOfficerIcon::OnCursor()
{
	_backgroundImage->OnCursor();
}

void UIOfficerIcon::NotOnCursor()
{
	_backgroundImage->NotOnCursor();
}