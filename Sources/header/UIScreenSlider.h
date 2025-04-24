#pragma once
#include "BaseUI.h"
/*
* ishihara
* UI�X�N���[���X���C�_�[
*/
class UIScreenSlider : public BaseUI
{
public:
	UIScreenSlider() {
	}
	UIScreenSlider(Layer setLayer)
		: BaseUI(setLayer) {
	}
	UIScreenSlider(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {
	}
	UIScreenSlider(const UIScreenSlider& obj)
		: BaseUI(obj) {
	}
	~UIScreenSlider() {
	}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
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
	// �X���C�_�[�̒l
	float _value;
	// �X���C�_�[�̐F
	COLOR_U8 color;
};
