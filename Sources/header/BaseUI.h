#pragma once
#include "BaseObject.h"
/*
* Ishihara
* UI���
*/
class BaseUI: public BaseObject
{
public:
	BaseUI() {}
	BaseUI(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) {
		Init(setPosition, setSize, layerSetting);
	}
	BaseUI(UISetting setting, LayerSetting layerSetting) {
		Init(setting.m_position, setting.m_size, layerSetting);
		SetSize(setting.m_size.x);
		SetText(setting.m_text);
	}
	BaseUI(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseUI(Layer setLayer,int setDrawHandle)
		: BaseObject(setLayer,setDrawHandle) {}
	BaseUI(const BaseUI& obj)
		: BaseObject(obj) {}
	~BaseUI() {}

	/// <summary>
	/// ������
	/// </summary>
	virtual void Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting);
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	void Proc() override;
	/// <summary>
	/// �`��
	/// </summary>
	void Draw() override;
	/// <summary>
	/// �j��
	/// </summary>
	void Teardown() override;
	/// <summary>
	/// ���W�̕ύX
	/// </summary>
	/// <param name="setPos"></param>
	void SetPos(Vector2 setPos) {
		position = setPos;
	}
	/// <summary>
	/// �傫���̕ύX
	/// </summary>
	/// <param name="setSize"></param>
	void SetSize(int setSize){
		textSize = setSize;
	}
	/// <summary>
	/// �e�L�X�g�̐ݒ�
	/// </summary>
	/// <param name="text"></param>
	void SetText(const std::string& setText) {
		text = setText;
	}
	/// <summary>
	/// �t�H���g�̐ݒ�
	/// </summary>
	/// <param name="setFont"></param>
	/// <param name="size"></param>
	/// <param name="thick"></param>
	void SetFontHandle(const char* setFont, int size, int thick){
		fontHandle = CreateFontToHandle(setFont, size, thick, DX_FONTTYPE_ANTIALIASING);
	}
protected:
	std::string text;
	int textGraph;
	int textSize;
	int fontHandle;
private:
	// ����
	std::string prevText = "";
};

