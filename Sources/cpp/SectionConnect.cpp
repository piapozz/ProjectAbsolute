#include "../header/SectionConnect.h"

#include "../header/Const.h"

void SectionConnect::Init(Transform setTransform, LayerSetting layerSetting)
{
	// ������
	BaseSection::Init(setTransform, layerSetting);
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