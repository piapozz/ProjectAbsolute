#include "../header/SecureRoom.h"
#include "../header/BaseEntity.h"

void SecureRoom::Init(Vector2 position, Vector2 size)
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
	BaseSection::Draw();
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

	// �����g�_�E���J�E���g������������
	_meltdownCount--;
	if (_meltdownCount > 0) return;

	// �����g�_�E���J�E���g��0�ɂȂ�����A�G���e�B�e�B�[��\��������
	_pEntity->SetRunawayCount(0);
	_pEntity->RunawayEvent();
}