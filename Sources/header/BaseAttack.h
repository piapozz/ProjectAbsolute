#include "BaseCharacter.h"
/*
* watanabe
* �U���̊��
*/
class BaseAttack
{
public:
	BaseAttack(){
	};
	~BaseAttack(){
	};

	/// <summary>
	/// �U��
	/// </summary>
	/// <param name="chara"></param>
	virtual void Attack(BaseCharacter* chara);

protected:
	/// <summary>
	/// �󂯎�������W�ɊԊu���J����
	/// </summary>
	/// <param name="position"></param>
	Vector2 GetLocation(Vector2 position);
	/// <summary>
	/// �����蔻����̃L�������擾
	/// </summary>
	/// <param name="location"></param>
	/// <returns></returns>
	std::vector<BaseObject*> GetHitBoxCharacters(Vector2 location);

	// �����蔻��̍L��
	Vector2 hitBoxSize = {HITBOX_SIZE_WIDTH, HITBOX_SIZE_HEIGHT};
	// �����蔻�肩��̊Ԋu
	Vector2 hitBoxSpace = {HITBOX_SIZE_WIDTH / HALF, ZERO};

private:
	const float HITBOX_SIZE_WIDTH = 100;
	const float HITBOX_SIZE_HEIGHT = 100;
	const float HITBOX_SPACE = 100;

	const int ZERO = 0;
	const int HALF = 2;

};