#pragma once
#include "BaseUI.h"
#include <functional>
/*
* Ishihara
* UI�{�^��
*/
class UIButton: public BaseUI
{
public:
	UIButton() {}
	UIButton(Vector2 pos, Vector2 size){
		Init(pos, size);
	}
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
	void ClickEvent() override {_callback();}

	static std::string StaticTypeName() {
		return "UIButton";
	}

	/// <summary>
	/// �R�[���o�b�N�̐ݒ�
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) {_callback = callback;}
private:
	// �R�[���o�b�N
	std::function<void()> _callback;
};

