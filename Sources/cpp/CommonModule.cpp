#include "../header/CommonModule.h"
#include "../header/Const.h"
#include "../header/BaseObject.h"

/// <summary>
/// �X�N���[�����W����X�e�[�W���W�ɕϊ�����
/// </summary>
/// <param name="screenPos"></param>
/// <param name="cameraHeight"></param>
/// <param name="cameraPos"></param>
/// <returns></returns>
Vector2 GetScreen2StagePos(Vector2 screenPos, float cameraHeight, Vector2 cameraPos)
{
	// �g�k�ƒ��S���W����ϊ�
	float ratio = cameraHeight / WINDOW_HEIGHT;
	Vector2 screenCentor = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2;
	// �X�N���[���̒��S���W����̋����Ɋg�k�������ăX�e�[�W�̒��S���W���狁�߂�
	Vector2 screenDistance = Vector2(screenPos.x - screenCentor.x, screenCentor.y - screenPos.y);
	return Vector2(cameraPos + screenDistance * ratio);
}

Vector2 Transform::GetWorldPosition()
{
	Vector2 result;
	if (parent != nullptr)
		result = position + parent->GetPosition();
	else
		result = position;
	return result;
}