#pragma once
#include <vector>
#include <string>
#include "DxLib.h"

// �l����
enum class DirFour
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,
    MAX
};
// �V�[���̖��O
enum class SceneName
{
	INVALID = -1,
	TITLE,
	MAIN,
	RESULT,
	OPTION,
	EXIT,

	MAX
};
// �\�����C���[
enum class Layer
{
	INVALID = -1,
	NONE_DRAW,
	BACK_GROUND,
	OBJECT,
	PLAYER,
	ENTITY,
	EFFECT,
	UI,

	MAX
};
// �����̎��
enum class SectionType
{
	INVALID = -1,
	NONE,
	ROOM,
	CORRIDOR,
	CONNECT,
	SECURE,

	MAX
};
// ����
enum class Direction
{
	INVALID = -1,
	UP,
	RIGHT,
	DOWN,
	LEFT,

	MAX
};
// ���
enum class Type
{
	RED = 0,
	WHITE,
	BLACK,
	PALE,
	MAX
};

// �X�e�[�W
const int SECTION_SIZE = 100;

// �F
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);

// �E�B���h�E
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// �֗�����
const float RAD2DEG = (float)(180 / DX_PI);