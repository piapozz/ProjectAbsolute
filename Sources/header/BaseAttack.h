#include "BaseCharacter.h"
/*
* watanabe
* UŒ‚‚ÌŠî’ê
*/
class BaseAttack
{
public:
	BaseAttack(){
	};
	~BaseAttack(){
	};

	/// <summary>
	/// UŒ‚
	/// </summary>
	/// <param name="chara"></param>
	virtual void Attack(BaseCharacter* chara);

protected:
	/// <summary>
	/// ó‚¯æ‚Á‚½À•W‚ÉŠÔŠu‚ğŠJ‚¯‚é
	/// </summary>
	/// <param name="position"></param>
	Vector2 GetLocation(Vector2 position);
	/// <summary>
	/// “–‚½‚è”»’è“à‚ÌƒLƒƒƒ‰‚ğæ“¾
	/// </summary>
	/// <param name="location"></param>
	/// <returns></returns>
	std::vector<BaseObject*> GetHitBoxCharacters(Vector2 location);

	// “–‚½‚è”»’è‚ÌL‚³
	Vector2 hitBoxSize = {HITBOX_SIZE_WIDTH, HITBOX_SIZE_HEIGHT};
	// “–‚½‚è”»’è‚©‚ç‚ÌŠÔŠu
	Vector2 hitBoxSpace = {HITBOX_SIZE_WIDTH / HALF, ZERO};

private:
	const float HITBOX_SIZE_WIDTH = 100;
	const float HITBOX_SIZE_HEIGHT = 100;
	const float HITBOX_SPACE = 100;

	const int ZERO = 0;
	const int HALF = 2;

};