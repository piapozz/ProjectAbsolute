#pragma once

// �O���錾
class Officer;

/*
 * Sein
 * Officer��State�̊��N���X
 */
class BaseOfficerState
{
public:
	virtual void Update(Officer* officer){}
	virtual void Enter(Officer* officer){}
	virtual void Exit(Officer* officer){}

};