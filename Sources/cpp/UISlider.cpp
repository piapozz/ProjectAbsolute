#include "../header/UISlider.h"
#include "../header/ObjectFactory.h"

void UISlider::Init(Transform setTransform, LayerSetting layerSetting)
{
	// 初期化
	BaseUI::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIText>(setTransform, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIImage>(setTransform, setLayer);
}

void UISlider::Proc()
{
	// アップデート
	BaseUI::Proc();
	Vector2 position = transform.GetWorldPosition();
	_pImage->SetPosition(position);
	_pText->SetPosition(position);
}

void UISlider::Draw()
{
	// ポリゴン
	Vector2 position = transform.GetWorldPosition();
	Vector2 scale = transform.scale;
	int x1 = position.x - scale.x / 2;
	int y1 = position.y - scale.y / 2;
	int x2 = x1 + (scale.x * _value);
	int y2 = position.y + scale.y / 2;
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
		pos3,
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
	
	// 描画
	BaseUI::Draw();
}

void UISlider::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}