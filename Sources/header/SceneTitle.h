#pragma once
#include "BaseScene.h"

class SceneTitle :
    public BaseScene
{
private:

    float TITLE_LOGO_X = 600;
    float TITLE_LOGO_Y = 600;

    int _titleLogoHandle = LoadGraph("Resources/Signal_Logo");

    const int TITLE_SELECT_NUMBER = 3;

    float alpha = 255;                  // �A���t�@�l
    float flickerSpeed = 0.05f;         // �_�ł̕ω����x
    float baseFrequency = 5.0f;         // ��{�̓_�Ŏ���
    float randomFrequencyOffset = 1.0f; // �����̃����_���Ȕ͈�


    int startTime;

public:

    SceneTitle();
    ~SceneTitle();

    void Init();
    void Proc();
    void Draw();
    int CheckChangeScene();
};

