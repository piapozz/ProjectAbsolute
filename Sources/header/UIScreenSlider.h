#pragma once
#include "../header/BaseUIScreen.h"
/*
* ishihara
* UI�X�N���[���X���C�_�[
*/
class UIScreenSlider : public BaseUIScreen
{
public:
	UIScreenSlider() {}
	UIScreenSlider(Layer setLayer): BaseUIScreen(setLayer) {}
	UIScreenSlider(Layer setLayer, int setDrawHandle): BaseUIScreen(setLayer, setDrawHandle) {}
	UIScreenSlider(const UIScreenSlider& obj): BaseUIScreen(obj) {}
	~UIScreenSlider() {}
	void Init(Vector2 setPosition, Vector2 setSize, bool fill);
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
	void SetColor(int r = 255, int g = 255, int b = 255) {
		_color = GetColor(r, g, b);
	}
private:
	// �X���C�_�[�̒l
	float _value;
	// �X���C�_�[�̐F
	int _color;
};
