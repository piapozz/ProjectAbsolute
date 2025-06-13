#include "../header/UIImage.h"

void UIImage::Init(Transform setTransform, LayerSetting layerSetting)
{
	BaseUI::Init(setTransform, layerSetting);
}

void UIImage::Proc()
{
	// アップデート
	BaseUI::Proc();
}

void UIImage::Draw()
{
	// 描画
	BaseObject::Draw();

	// 四角を描画
	Vector2 position = transform.GetWorldPosition();
	Vector2 scale = transform.scale;
	int x1 = position.x + scale.x / 2;
	int y1 = position.y + scale.y / 2;
	int x2 = position.x - scale.x / 2;
	int y2 = position.y - scale.y / 2;

	VECTOR Pos1 = VGet(x1, y1, 0);
	VECTOR Pos2 = VGet(x2, y1, 0);
	VECTOR Pos3 = VGet(x2, y2, 0);
	VECTOR Pos4 = VGet(x1, y2, 0);

	DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
	DrawLine3D(Pos2, Pos3, GetColor(255, 255, 255));
	DrawLine3D(Pos3, Pos4, GetColor(255, 255, 255));
	DrawLine3D(Pos4, Pos1, GetColor(255, 255, 255));
}

void UIImage::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}
