#pragma once
#include "BaseUI.h"
#include <functional>
/*
* Ishihara
* UI�X�N���[���{�^���v
*/
class UIScreenButton : public BaseUI
{
public:
	UIScreenButton() {
	}
	UIScreenButton(Layer setLayer)
		: BaseUI(setLayer) {
	}
	UIScreenButton(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {
	}
	UIScreenButton(const UIScreenButton& obj)
		: BaseUI(obj) {
	}
	~UIScreenButton() {
	}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override {
		_callback();
	}
	/// <summary>
	/// �R�[���o�b�N�̐ݒ�
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) {
		_callback = callback;
	}
private:
	// �R�[���o�b�N
	std::function<void()> _callback;
};
