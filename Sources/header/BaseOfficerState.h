#pragma once

// �O���錾
class BaseOfficer;

/*
 * Sein
 * Officer��State�̊��N���X
 */
class BaseOfficerState
{
public:
	virtual void Update(BaseOfficer* officer){}
	virtual void Enter(BaseOfficer* officer){}
	virtual void Exit(BaseOfficer* officer){}

};