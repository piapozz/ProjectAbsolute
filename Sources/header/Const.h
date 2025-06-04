#pragma once
#include <vector>
#include <string>
#include "DxLib.h"
#include "CommonModule.h"

enum class ObjectType{
	INVALID = -1,
	SCREEN_UI,
	UI,
	CHARACTER,
	SECTION,

	MAX
};
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
	NONE_INTERACT,
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
// ���
enum class Type
{
	INVALID = -1,
	RED,
	WHITE,
	BLACK,
	PALE,
	MAX
};

enum class OfficerType
{
	NONE = -1,
	PLAYER,
	MOB,

	MAX
};

enum class CharacterStateID
{
	NONE = -1,
	IDLE,
	MOVE,
	OPERATION,
	OPERATION_MOVE,
	FIGHT,
	PANIC,
	DEAD,

	MAX
};

enum class CharacterGroup
{
	INVALID = -1,
	OFFICER,
	ENTITY,
	OTHER,
};

// UI�ݒ�\����
typedef struct{
	Vector2 m_position; // ���W
	Vector2 m_size;		// �傫��
	int m_textColor;	// �e�L�X�g�̐F
	std::string m_text; // �e�L�X�g���e
	bool m_fill;		// �h��Ԃ��t���O
} UISetting;;

// �X�e�[�W
const int SECTION_SIZE_X = 150;
const int SECTION_SIZE_Y = 100;
// �X�e�[�W�̃T�C�Y
const int STAGE_SIZE = 7;

// �F
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);

// �E�B���h�E
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// �֗�����
const float RAD2DEG = (float)(180 / DX_PI);

// �X�e�[�^�X�֌W
const int MINIMUM_HEALTH = 0;
const int MINIMUM_MENTAL = 0;