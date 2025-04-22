#include "../header/UISlider.h"

void UISlider::Init(Vector2 setPosition, Vector2 setSize)
{
	// 初期化
	BaseUI::Init(setPosition, setSize);
}

void UISlider::Proc()
{
	// アップデート
	BaseUI::Proc();

	if (prevText != _buttonText)
	{
		int w = GetDrawStringWidthToHandle(_buttonText.c_str(), strlen(_buttonText.c_str()), fontHandle);
		int h = GetFontSizeToHandle(fontHandle);

		int texW = w + 50;
		int texH = h + 50;

		textGraph = MakeScreen(texW, texH, TRUE);

		SetDrawScreen(textGraph);
		ClearDrawScreen();

		int drawX = texW / 2 - w / 2;
		int drawY = texH / 2 - h / 2;
		DrawStringToHandle(drawX, drawY, _buttonText.c_str(), GetColor(255, 255, 255), fontHandle);
		SetDrawScreen(DX_SCREEN_BACK);

		prevText = _buttonText;
	}
}

void UISlider::Draw()
{
	// 描画
	BaseUI::Draw();

	// ポリゴン
	int x1 = position.x - objectSize.x / 2;
	int y1 = position.y - objectSize.y / 2;
	int x2 = x1 + (objectSize.x * _value);
	int y2 = position.y + objectSize.y / 2;
	VECTOR pos1 = VGet(x1, y1, 0.0f);
	VECTOR pos2 = VGet(x1, y2, 0.0f);
	VECTOR pos3 = VGet(x2, y2, 0.0f);
	VECTOR pos4 = VGet(x2, y1, 0.0f);
	VERTEX3D Vertex[6];
	std::vector<VECTOR> vertexPos = {
		pos1,
		pos2,
		pos3,
		pos1,
		pos2,
		pos4
	};

	// ２ポリゴン分の頂点のデータをセット
	for (int i = 0; i < 6; ++i)
	{
		Vertex[i].pos  = vertexPos[i];
		Vertex[i].norm = VGet(0.0f, 0.0f, -1.0f);
		Vertex[i].dif  = color;
		Vertex[i].spc  = color;
		Vertex[i].u    = 0.0f;
		Vertex[i].v    = 0.0f;
		Vertex[i].su   = 0.0f;
		Vertex[i].sv   = 0.0f;
	}
	// ２ポリゴンの描画
	DrawPolygon3D(Vertex, 2, DX_NONE_GRAPH, FALSE);

	// テキスト
	VECTOR pos = VGet(position.x, position.y, 0.0f);
	DrawBillboard3D(
		pos,
		0.5f, 0.5f,
		((objectSize.x + objectSize.y) / 2),
		0,
		textGraph,
		TRUE
	);
}

void UISlider::Teardown()
{
	// 破棄
	BaseUI::Teardown();
	if (textGraph != -1)
	{
		DeleteGraph(textGraph);
		textGraph = -1;
	}
}