#include "BaseCharacter.h"
/*
* watanabe
* �U���̊��
*/
class BaseAttack
{
public:
	BaseAttack(){};
	~BaseAttack(){};

	/// <summary>
	/// �U��
	/// </summary>
	/// <param name="chara"></param>
	/// <param name="attackPos"></param>
	/// <param name="attackSize"></param>
	void Attack(BaseCharacter* chara, Vector2 attackPos, Vector2 attackSize);
private:
};