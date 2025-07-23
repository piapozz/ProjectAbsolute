#pragma once
#include <vector>
#include <string>
#include "DxLib.h"
#include "CommonModule.h"

enum class ObjectType
{
	INVALID = -1,
	SECTION,
	CHARACTER,
	UI,
	SCREEN_UI,

	MAX
};
// 四方向
enum class DirFour
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,

    MAX
};
// シーンの名前
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
// フェーズの名前
enum class PhaseName
{
	INVALID = -1,
	SELECT,
	STANDBY,
	MAIN,
	RESULT,
	MAX
};
// 表示レイヤー
enum class Layer
{
	INVALID = -1,
	BACK,
	MIDDLE,
	FRONT,

	MAX
};
// 部屋の種類
enum class SectionType
{
	INVALID = -1,
	NONE,
	RESPAWN,
	ROOM,
	CORRIDOR,
	CONNECT,
	SECURE,

	MAX
};
// 種類
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
	FIGHT_MOVE,
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

enum class Level
{
	INVALID = -1,
	I,
	II,
	III,
	IV,
	V,
	MAX
};

// BGM
enum class BGM
{
	INVALID = -1,
	TITLE,
	MAIN,
	OTHER,

	MAX
};

// SE
enum class SE
{
	INVALID = -1,
	CLICK,
	ALERT,
	ATTACK,
	DEAD,

	MAX
};

// レイヤー設定構造体
typedef struct LayerSetting
{
	bool m_active = true;
	bool m_interact = true;
	Layer m_layer = Layer::BACK;
	// デフォルトコンストラクタ
	LayerSetting(bool active, bool interact, Layer layer): m_active(active), m_interact(interact), m_layer(layer){ }
};

// エンティティの管理データ
struct EntityManagementData
{
	int ID;
	int roomID;
	int operationCount;
	bool isLockInformation;
	bool isLockOperation[(int)Type::MAX];
	bool isLockManagement;
	bool isLockRunaway;
	bool isLockWeapon;
	bool isLockSuit;
};

const std::vector<std::string> nameList =
{
	"Sakakura",
	"Toshihiro",
	"Piapozz",
	"Saranath",
	"Kalastathar",
	"Ansamath",
	"Valantal",
	"Jalanal",
	"Adanathar",
	"Kavalan",
};

// 職員のデータ
struct OfficerInitData
{
	OfficerInitData()
	{
		int index = GetRand(nameList.size() - 1);
		name = nameList[index];
	}

	std::string name = "";
	Vector2 position = Vector2(0, 0);
	int health = 100;
	int mental = 100;

	int suitID = -1;
	int weaponID = -1;
	OfficerType type = OfficerType::NONE;
	int param[(int)Type::MAX] ={
		10, 10, 10, 10
	};
};

// ステージ
const int SECTION_SIZE_X = 150;
const int SECTION_SIZE_Y = 100;
// ステージのサイズ
const int STAGE_SIZE = 7;

// 色
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);
const int COLOR_ORANGE = GetColor(205, 133, 63);
const int COLOR_YELLOW = GetColor(255, 255, 0);

// ウィンドウ
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// 便利数字
const float RAD2DEG = (float)(180 / DX_PI);

// ステータス関係
const int MINIMUM_HEALTH = 0;
const int MINIMUM_MENTAL = 0;

// カーソル
const int CURSOR_SIZE = 20;

// フォント
const int FONT_SIZE_MAX = 100;

// 最大日程
const int MAX_DAY = 24;

// BGMのファイルパス
const std::vector<std::string> BGMFilePath = {
	"Resources/Sounds/Title.mp3",
	"Resources/Sounds/Main.mp3",
	"Resources/Sounds/Other.mp3"
};
// SEのファイルパス
const std::vector<std::string> SEFilePath = {
	"Resources/Sounds/Decide.mp3",
	"Resources/Sounds/Warning.mp3",
	"Resources/Sounds/Attack.mp3",
	"Resources/Sounds/DeathVoice.mp3",
};

// 文字列に変換
inline std::string ToString(Type type)
{
	switch (type)
	{
		case Type::RED:    return "Red";
		case Type::WHITE:  return "White";
		case Type::BLACK:  return "Black";
		case Type::PALE:   return "Pale";
		case Type::INVALID:return "Invalid";
		default:           return "Unknown";
	}
}

// 色としての変換
inline int ToColor(Type type)
{
	switch (type)
	{
		case Type::RED:    return GetColor(255, 100, 100);
		case Type::WHITE:  return GetColor(255, 255, 255);
		case Type::BLACK:  return GetColor(200, 100, 200);
		case Type::PALE:   return GetColor(100, 200, 200);
		default:           return GetColor(128, 128, 128);
	}
}

// レベルをローマ数字に変換
inline std::string ToRomanNumber(Level level)
{
	switch (level)
	{
		case Level::I:		return "I";
		case Level::II:		return "II";
		case Level::III:	return "III";
		case Level::IV:		return "IV";
		case Level::V:		return "V";
		default:			return "Unknown";
	}
}

// タイプを作業の文字列へ変換
inline std::string ToOperation(Type type)
{
	switch (type)
	{
		case Type::RED:    return "世話";
		case Type::WHITE:  return "観察";
		case Type::BLACK:  return "接触";
		case Type::PALE:   return "危害";
		default:           return "";
	}
}
