#include "../header/SectionConnect.h"

#include "../header/Const.h"

void SectionConnect::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	// ������
	BaseSection::Init(setPosition, setSize, layerSetting);
	layer = layerSetting.m_layer;
}

void SectionConnect::Proc()
{
	// �A�b�v�f�[�g
	BaseSection::Proc();
}

void SectionConnect::Draw()
{
	// �`��
	BaseSection::Draw();
}

void SectionConnect::Teardown()
{
	// �j��
	BaseSection::Teardown();
}