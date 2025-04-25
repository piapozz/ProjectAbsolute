#pragma once
#include "../header/BaseUIScreen.h"
#include <functional>
/*
* Ishihara
* UI�X�N���[���{�^��
*/
class UIScreenButton : public BaseUIScreen
{
public:
	UIScreenButton() {}
	UIScreenButton(Layer setLayer)
		: BaseUIScreen(setLayer) {}
	UIScreenButton(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {}
	UIScreenButton(const UIScreenButton& obj)
		: BaseUIScreen(obj) {}
	~UIScreenButton() {}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override { _callback(); }
	/// <summary>
	/// �R�[���o�b�N�̐ݒ�
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) { _callback = callback; }
private:
	// �R�[���o�b�N
	std::function<void()> _callback;
	// �X�N���[�����W
	Vector2 _screenPos;
};
