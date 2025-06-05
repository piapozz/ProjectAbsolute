#include "../header/UISlider.h"

void UISlider::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	// ������
	BaseUI::Init(setPosition, setSize, layerSetting);
}

void UISlider::Proc()
{
	// �A�b�v�f�[�g
	BaseUI::Proc();
}

void UISlider::Draw()
{
	// �|���S��
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
		pos3,
		pos4
	};

	// �Q�|���S�����̒��_�̃f�[�^���Z�b�g
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
	// �Q�|���S���̕`��
	DrawPolygon3D(Vertex, 2, DX_NONE_GRAPH, FALSE);
	
	// �`��
	BaseUI::Draw();
}

void UISlider::Teardown()
{
	// �j��
	BaseUI::Teardown();
}