#include "../header/BaseUI.h"
#include "../header/ObjectManager.h"
#include "../header/Camera.h"

void BaseUI::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	fontHandle = CreateFontToHandle("�l�r �S�V�b�N", 24, 1);
	textGraph = MakeScreen(128, 32, TRUE); 
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::UI;
	textSize = 100;
	active = layerSetting.m_active;
	interactable = layerSetting.m_interact;
	layer = layerSetting.m_layer;
}

void BaseUI::Proc()
{
	// �A�b�v�f�[�g
	BaseObject::Proc();

	if (prevText != text)
	{
		const int padding = 50;

		int w = GetDrawStringWidthToHandle(text.c_str(), static_cast<int>(text.length()), fontHandle);
		int h = GetFontSizeToHandle(fontHandle);

		int texW = w + padding;
		int texH = h + padding;

		// �Â��O���t�B�b�N���폜
		if (textGraph != -1)
		{
			DeleteGraph(textGraph);
		}

		// �`���ƕ`���Ԃ̕ۑ�
		int prevScreen = GetDrawScreen();

		// ���z��ʍ쐬�ƕ`��
		textGraph = MakeScreen(texW, texH, TRUE);
		SetDrawScreen(textGraph);

		// ������Ԃŕ`��
		SetDrawArea(0, 0, texW, texH);

		int drawX = texW / 2 - w / 2;
		int drawY = texH / 2 - h / 2;
		DrawStringToHandle(drawX, drawY, text.c_str(), GetColor(255, 255, 255), fontHandle);

		// �`���Ԃ𕜌�
		SetDrawScreen(prevScreen);
		Camera::instance->UpdateCamera();

		prevText = text;
	}
}

void BaseUI::Draw()
{
	// �`��
	BaseObject::Draw();

	// �l�p��`��
	int x1 = position.x + objectSize.x / 2;
	int y1 = position.y + objectSize.y / 2;
	int x2 = position.x - objectSize.x / 2;
	int y2 = position.y - objectSize.y / 2;

	VECTOR Pos1 = VGet(x1, y1, 0);
	VECTOR Pos2 = VGet(x2, y1, 0);
	VECTOR Pos3 = VGet(x2, y2, 0);
	VECTOR Pos4 = VGet(x1, y2, 0);

	DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
	DrawLine3D(Pos2, Pos3, GetColor(255, 255, 255));
	DrawLine3D(Pos3, Pos4, GetColor(255, 255, 255));
	DrawLine3D(Pos4, Pos1, GetColor(255, 255, 255));

	// �e�L�X�g
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

void BaseUI::Teardown()
{
	// �j��
	BaseObject::Teardown();

	if (textGraph != -1)
	{
		DeleteGraph(textGraph);
		textGraph = -1;
	}
	DeleteFontToHandle(fontHandle);
}
