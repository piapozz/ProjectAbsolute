#pragma once

// ‘O•ûéŒ¾
class BaseOfficer;

/*
 * Sein
 * Officer‚ÌState‚ÌŠî’êƒNƒ‰ƒX
 */
class BaseOfficerState
{
public:
	virtual void Update(BaseOfficer* officer){}
	virtual void Enter(BaseOfficer* officer){}
	virtual void Exit(BaseOfficer* officer){}

};