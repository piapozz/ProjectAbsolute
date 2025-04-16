#include "../header/SecureRoom.h"

void SecureRoom::Init(Vector2 position, int size)
{
	BaseSection::Init(position, size);
	sectionType = SectionType::SECURE;
	layer = Layer::OBJECT;
}

void SecureRoom::Proc()
{
	MeltdownProc();
}

void SecureRoom::Draw()
{
	// 四角を描画
	int x1 = position.x + SECTION_SIZE / 2;
	int y1 = position.y + SECTION_SIZE / 2;
	int x2 = position.x - SECTION_SIZE / 2;
	int y2 = position.y - SECTION_SIZE / 2;

	VECTOR Pos1 = VGet(x1, y1, 0);
	VECTOR Pos2 = VGet(x2, y1, 0);
	VECTOR Pos3 = VGet(x2, y2, 0);
	VECTOR Pos4 = VGet(x1, y2, 0);

	DrawLine3D(Pos1, Pos2, GetColor(255, 255, 0)) ;
	DrawLine3D(Pos2, Pos3, GetColor(255, 255, 0)) ;
	DrawLine3D(Pos3, Pos4, GetColor(255, 255, 0)) ;
	DrawLine3D(Pos4, Pos1, GetColor(255, 255, 0)) ;
}

void SecureRoom::Teardown()
{
	delete _pEntity;
}

void SecureRoom::StartMeltdown()
{
	_isMeltdown = true;
	_meltdownCount = _MELTDOWN_COUNT;
}

void SecureRoom::MeltdownProc()
{
	if (!_isMeltdown || !_pEntity->CanMeltdown()) return;

	// メルトダウンカウントを減少させる
	_meltdownCount--;
	if (_meltdownCount > 0) return;

	// メルトダウンカウントが0になったら、エンティティーを暴走させる
	_pEntity->SetRunawayCount(0);
	_pEntity->RunawayEvent();
}