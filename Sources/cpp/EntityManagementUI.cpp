#include "../header/EntityManagementUI.h"
#include "../header/EntityManagementTipsUI.h"

void EntityManagementUI::Draw()
{
	// �Ǘ����@���ォ�珇�ɕ\��
	for (int i = 0, max = _tipsUIList.size(); i < max; i++)
	{
		_tipsUIList[i]->Draw();
	}
}

void EntityManagementUI::SetActive(bool active)
{
	
}