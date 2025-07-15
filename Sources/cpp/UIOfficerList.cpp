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
	DrawOfficerList();
}

void UIOfficerList::Teardown()
{

}

void UIOfficerList::DrawOfficerList()
{
	for (UIOfficerIcon* officer : officerIcons)
	{
		if (officer == nullptr) continue;

		officer->Draw();
	}
}

void UIOfficerList::AddOfficer(BaseOfficer* officer)
{
	// オフィサーを非表示
	officer->SetActive(false);
	officerList.push_back(officer);

	// オフィサーアイコンを生成
	Transform trans = Transform(Vector2(0, 0), Vector2(1, 1), this);
	LayerSetting layer = {true, true, Layer::MIDDLE};
	UIOfficerIcon* icon = ObjectFactory::Instance().CreateWithArgs<UIOfficerIcon>(trans, layer);
	icon->SetOfficer(officer);
	icon->SetOfficerList(this);
	officerIcons.push_back(icon);

	// アイコンの位置を設定
	SetIconPosition();
}

void UIOfficerList::RemoveOfficer(BaseOfficer* officer)
{
	auto it = std::find(officerList.begin(), officerList.end(), officer);
	if (it != officerList.end())
	{
		officerList.erase(it);
	}
	auto iconIt = std::find_if(officerIcons.begin(), officerIcons.end(),
		[officer](UIOfficerIcon* icon) { return icon->GetOfficer() == officer; });
	if (iconIt != officerIcons.end())
	{
		UIOfficerIcon* icon = *iconIt;
		icon->Teardown();
		officerIcons.erase(iconIt);
	}
	SetIconPosition();
}

void UIOfficerList::SetIconPosition()
{
	float iconWidth = OFFICER_ICON_SIZE.x;
	float iconHeight = OFFICER_ICON_SIZE.y;
	float parentWidth = GetTransform().scale.x;
	float parentHeight = GetTransform().scale.y;

	const size_t columns = parentWidth / iconWidth;
	const size_t totalIcons = officerIcons.size();

	Vector2 scale = Vector2(iconWidth / parentWidth, iconHeight / parentHeight);

	// グリッドの左上原点
	float offsetX = -(parentWidth / 2);
	float offsetY = -(parentHeight / 2);

	for (size_t i = 0; i < totalIcons; ++i)
	{
		UIOfficerIcon* icon = officerIcons[i];
		if (!icon) continue;

		size_t col = i % columns;
		size_t row = i / columns;

		float x = offsetX + ((col + 0.5f) * iconWidth);
		float y = offsetY + ((row + 0.5f) * iconHeight);

		Vector2 pos = Vector2(x / (parentWidth / 2), y / (parentHeight / 2));

		icon->SetSize(scale);
		icon->SetPosition(pos); 
	}
}
