#include "../header/BaseSection.h"
#include "../header/ObjectManager.h"
#include "../header/BaseCharacter.h"
#include "../header/PhaseMain.h"
#include "../header/OfficerPlayer.h"

void BaseSection::Init(Transform setTransform, LayerSetting layerSetting)
{
	// 初期化
	sectionType = SectionType::INVALID;
	transform = setTransform;
	objectType = ObjectType::SECTION;
	active = layerSetting.m_active;
	interactable = layerSetting.m_interact;
	layer = layerSetting.m_layer;
}

void BaseSection::Proc()
{
	// アップデート
	BaseObject::Proc();
}

void BaseSection::Draw()
{
	// 描画
	BaseObject::Draw();

	// 四角を描画
	Vector2 position = transform.GetWorldPosition();
	Vector2 scale = transform.scale;
	int x1 = position.x + scale.x / 2;
	int y1 = position.y + scale.y / 2;
	int x2 = position.x - scale.x / 2;
	int y2 = position.y - scale.y / 2;

	VECTOR Pos1 = VGet(x1, y1, 0);
	VECTOR Pos2 = VGet(x2, y1, 0);
	VECTOR Pos3 = VGet(x2, y2, 0);
	VECTOR Pos4 = VGet(x1, y2, 0);

	DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
	DrawLine3D(Pos2, Pos3, GetColor(255, 255, 255));
	DrawLine3D(Pos3, Pos4, GetColor(255, 255, 255));
	DrawLine3D(Pos4, Pos1, GetColor(255, 255, 255));
}

void BaseSection::Teardown()
{
	// 破棄
	BaseObject::Teardown();
}

std::vector<BaseCharacter*> BaseSection::GetCharacters()
{
	// キャラクターの取得
	Vector2 position = transform.GetWorldPosition();
	Vector2 scale = transform.scale;
	auto charas = ObjectManager::Instance().FindRectAllObject(position, scale, ObjectType::CHARACTER);
	std::vector<BaseCharacter*> characters;
	for (BaseObject* obj : charas)
	{
		if (obj->GetType() == ObjectType::CHARACTER)
		{
			characters.push_back(static_cast<BaseCharacter*>(obj));
		}
	}
	return characters;
}

void BaseSection::ClickEvent()
{
	std::vector<OfficerPlayer*> selectOfficerList = PhaseMain::GetSelectOfficerList();
	if (selectOfficerList.empty()) return;

	// この部屋にキャラクターを移動させる
	// キャラ移動が可能なら移動
	if (selectOfficerList[0]->GetImpossible())
	{
		selectOfficerList[0]->ChangeMoveState(this);
		return;
	}
}