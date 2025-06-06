#include "../header/CharacterStateFight.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/BaseAttack.h"


void CharacterStateFight::Update(BaseCharacter* character)
{
	ObjectManager& objectManager = ObjectManager::Instance();
	Vector2 attackerPos = character->GetPosition();

	_targetCharacter = selector->SelectTargets(character);

	// ‡@“¯‚¶‹æ‰æ‚É“G‘Î‘ÎÛ‚ª‚¢‚é‚©ŒŸõ
	BaseObject* attackerSection = objectManager.FindPosObject(attackerPos, ObjectType::SECTION);
	Vector2 sectionPosition = attackerSection->GetPosition();
	Vector2 sectionSize = attackerSection->GetSize();

	std::vector<BaseObject*> targetCharaList = objectManager.FindRectAllObject(sectionPosition, sectionSize, ObjectType::CHARACTER);
	
	// ‹æ‰æ‚É“G‘Î‘ÎÛ‚ª‚¢‚È‚©‚Á‚½‚ç
	if (targetCharaList.empty())
	{
		// ‡A‚¢‚È‚¢‚È‚çŒo˜H’Tõ‚µ‚Ä“¯‚¶•”‰®‚Ü‚ÅˆÚ“®
		// ˆÚ“®‚ªŠ®—¹‚µ‚½‚çŒo˜H’Tõ‚µ‚È‚¨‚·
		// character->Move(targetCharacter)
		return;
	}

	// ‡A‚¢‚é‚È‚çË’öŒ—“à‚Ü‚Å•”‰®“àˆÚ“®
	// character->Move()

	// ‡@`‡B‚ÌŠÔ‚É‘ÎÛ‚Æ‚Ì‹——£‚ğŒ©‚ÄŠÔ‡‚¢‚È‚çUŒ‚‚·‚é
	BaseAttack* attack = character->GetAttack();
	// attack->Attack(_targetCharacter);

	// (“¯‚¶‹æ‰æ“à‚Ö‚ÌUŒ‚‚È‚ç‚±‚Ì‘O‚É“¯‚¶‹æ‰æ‚É‚¢‚é‚©’²‚×‚é‚±‚Æ)
}

void CharacterStateFight::Enter(BaseCharacter* character)
{

}

void CharacterStateFight::Exit(BaseCharacter* character)
{

}