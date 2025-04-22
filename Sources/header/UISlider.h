#pragma once  
#include "BaseUI.h"	

class UISlider: public BaseUI
{
public:
	UISlider() {}
	UISlider(Layer setLayer)
		: BaseUI(setLayer) {}
	UISlider(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {}
	UISlider(const UISlider& obj)
		: BaseUI(obj) {}
	~UISlider() {}

	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	/// <summary>
	/// �e�L�X�g�̐ݒ�
	/// </summary>
	/// <param name="text"></param>
	void SetButtonText(const std::string& text) {
		_buttonText = text;
	}
	/// <summary>
	/// �l�̐ݒ�
	/// </summary>
	/// <param name="value"></param>
	void SetValue(float value) {
		_value = value;
	}
	/// <summary>
	/// �F�̐ݒ�
	/// </summary>
	void SetColor(int r = 255, int g = 255, int b = 255, int a = 255) {
		color = GetColorU8(r, g, b, a);
	}
private:
	// �X���C�_�[�̕���
	std::string _buttonText;
	std::string prevText = "";
	// �X���C�_�[�̒l
	float _value;
	// �X���C�_�[�̐F
	COLOR_U8 color;
};

