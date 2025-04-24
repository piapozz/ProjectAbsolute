#pragma once
#include "BaseUI.h"
/*
* ishihara
* UIスクリーンテキスト
*/
class UIScreenText : public BaseUI
{
public:
	UIScreenText() {
	}
	UIScreenText(Layer setLayer)
		: BaseUI(setLayer) {
	}
	UIScreenText(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {
	}
	UIScreenText(const UIScreenText& obj)
		: BaseUI(obj) {
	}
	~UIScreenText() {
	}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
private:
};
