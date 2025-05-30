#pragma once
#include "BaseUI.h"
/*
* ishihara
* UI�e�L�X�g
*/
class UIText : public BaseUI
{
public:
	UIText() {
	}
	UIText(Layer setLayer)
		: BaseUI(setLayer) {
	}
	UIText(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {
	}
	UIText(const UIText& obj)
		: BaseUI(obj) {
	}
	~UIText() {
	}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
private:
};