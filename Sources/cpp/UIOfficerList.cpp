#include "../header/UIOfficerList.h"
#include "../header/ObjectFactory.h"

void UIOfficerList::Init(Transform setTrasnform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTrasnform, layerSetting);

	Transform trans = Transform(Vector2(0, 0), Vector2(1, 1), this);
	LayerSetting layer = layerSetting;
	backgroundImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, false, layer);
}

void UIOfficerList::Proc()
{
	backgroundImage->Proc();
}

void UIOfficerList::Draw()
{
	backgroundImage->Draw();
}

void UIOfficerList::Teardown()
{

}
