#pragma once
/*
* Sakakura
* フェーズの基底
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

