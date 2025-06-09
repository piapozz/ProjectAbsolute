#include "../header/UIText.h"
#include "../header/Camera.h"

void UIText::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) {
	BaseUI::Init(setPosition, setSize, layerSetting);
	fontHandle = CreateFontToHandle("ÇlÇr ÉSÉVÉbÉN", 24, 1);
	textGraph = MakeScreen(128, 32, TRUE);
	textSize = 100;
}

void UIText::Proc() {
	BaseUI::Proc();
	if (prevText != text)
	{
		const int padding = 50;

		int w = GetDrawStringWidthToHandle(text.c_str(), static_cast<int>(text.length()), fontHandle);
		int h = GetFontSizeToHandle(fontHandle);

		int texW = w + padding;
		int texH = h + padding;

		// å√Ç¢ÉOÉâÉtÉBÉbÉNÇçÌèú
		if (textGraph != -1)
		{
			DeleteGraph(textGraph);
		}

		// ï`âÊêÊÇ∆ï`âÊèÛë‘ÇÃï€ë∂
		int prevScreen = GetDrawScreen();

		// âºëzâÊñ çÏê¨Ç∆ï`âÊ
		textGraph = MakeScreen(texW, texH, TRUE);
		SetDrawScreen(textGraph);

		// èâä˙èÛë‘Ç≈ï`âÊ
		SetDrawArea(0, 0, texW, texH);

		int drawX = texW / 2 - w / 2;
		int drawY = texH / 2 - h / 2;
		DrawStringToHandle(drawX, drawY, text.c_str(), GetColor(255, 255, 255), fontHandle);

		// ï`âÊèÛë‘Çïúå≥
		SetDrawScreen(prevScreen);
		Camera::instance->UpdateCamera();

		prevText = text;
	}
}

void UIText::Draw() {
	BaseUI::Draw();

	// ÉeÉLÉXÉg
	VECTOR pos = VGet(position.x, position.y, 0.0f);
	DrawBillboard3D(
		pos,
		0.5f, 0.5f,
		textSize,
		0,
		textGraph,
		TRUE
	);
}

void UIText::Teardown() {
	BaseUI::Teardown();
	DeleteFontToHandle(fontHandle);

	if (textGraph != -1)
	{
		DeleteGraph(textGraph);
		textGraph = -1;
	}
	DeleteFontToHandle(fontHandle);
}
