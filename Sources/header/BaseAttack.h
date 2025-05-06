#include "BaseCharacter.h"
/*
* watanabe
* UŒ‚‚ÌŠî’ê
*/
class BaseAttack
{
public:
	BaseAttack(){};
	~BaseAttack(){};

	/// <summary>
	/// UŒ‚
	/// </summary>
	/// <param name="chara"></param>
	/// <param name="attackPos"></param>
	/// <param name="attackSize"></param>
	void Attack(BaseCharacter* chara);
protected:
	Vector2 hitBoxSize;

private:
	std::vector<BaseCharacter*> targetList;
};