#pragma once
#include "BaseUI.h"
#include <string>

class UIButton: public BaseUI
{
public:
	UIButton() {}
	UIButton(Layer setLayer)
		: BaseUI(setLayer) {}
	UIButton(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {}
	UIButton(const UIButton& obj)
		: BaseUI(obj) {}
	~UIButton() {}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	/// <summary>
	/// �\���̐؂�ւ�
	/// </summary>
	/// <param name="active"></param>
	void SetActive(bool active);
	/// <summary>
	/// �e�L�X�g�̐ݒ�
	/// </summary>
	/// <param name="text"></param>
	void SetButtonText(const std::string& text) { _buttonText = text; }
	/// <summary>
	/// ��ʂɒǏ]�����邩�ǂ���
	/// </summary>
	/// <param name="is2D"></param>
	void Set2D(bool is2D) { _is2D = is2D; }
private:
	// �{�^���̕���
	std::string _buttonText;
	// "2D��3D��
	bool _is2D;
};

