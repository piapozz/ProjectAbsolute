#include "../header/UIOfficerList.h"
#include "../header/ObjectFactory.h"
#include "../header/UIOfficerIcon.h"

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

void UIOfficerList::DrawOfficerList()
{
	for (BaseOfficer* officer : officerList)
	{
		if (officer == nullptr) continue;

		Transform trans = Transform(Vector2(0, 0), Vector2(1, 1));
		LayerSetting layer = {true, true, Layer::MIDDLE};
		UIOfficerIcon* icon = ObjectFactory::Instance().CreateWithArgs<UIOfficerIcon>(
		);
		icon->SetOfficer(officer);
	}
}