#pragma once

// ‘O•ûéŒ¾
class Officer;

/*
 * Sein
 * Officer‚ÌState‚ÌŠî’êƒNƒ‰ƒX
 */
class BaseOfficerState
{
public:
	virtual void Updata(Officer* officer){}
	virtual void Enter(Officer* officer){}
	virtual void Exit(Officer* officer){}

};