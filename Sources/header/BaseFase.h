#pragma once
/*
* Sakakura
* �t�F�[�Y�̊��
*/
class BaseFase
{
public:
	BaseFase();
	~BaseFase();

protected:
	inline virtual void Initialize(){};
	inline virtual void Proc(){};
	inline virtual void Draw(){};
};

