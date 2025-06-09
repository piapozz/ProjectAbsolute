#include "../header/CharacterStateIdle.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"

void CharacterStateIdle::Update(BaseCharacter* character)
{
	ObjectManager& objectManager = ObjectManager::Instance();

	int nowCount = GetNowCount();
	int elapsed = nowCount - _startCount;

	if (elapsed >= _waitCount)
	{
		Vector2 characterPosition = character->GetPosition();

		BaseObject* targetSectionObject = objectManager.FindPosObject(characterPosition, ObjectType::SECTION);
		Vector2 sectionPosition = targetSectionObject->GetPosition();
		Vector2 sectionSize = targetSectionObject->GetSize();

		// �����̉E�[���獶�[
		int leftPoint = sectionPosition.x - sectionSize.x / 2;
		int rightPoint = sectionPosition.x + sectionSize.x / 2;
		float randValue = GetRand(rightPoint - leftPoint) + leftPoint;

		Vector2 nextPosition = {randValue, characterPosition.y};

		// ���Ԃ��������畔�����œK���Ɉړ�
		character->ChangeMoveState(nextPosition, CharacterStateID::IDLE);
		return;
	}
}

void CharacterStateIdle::Enter(BaseCharacter* character)
{
	character->color = IDLE;
	character->stateID = CharacterStateID::IDLE;

	_startCount = GetNowCount();
}

void CharacterStateIdle::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}