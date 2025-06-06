﻿#include "../header/CharacterStateMove.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"

CharacterStateMove::CharacterStateMove(std::vector<Vector2> targetPosList)
{
	_routeList = targetPosList;
}

void CharacterStateMove::Update(BaseCharacter* character)
{
	//bool finishMove = false;
	//finishMove = character->CharacterMove(_routeList, speed);
	//if (finishMove)character->ChangeState(OfficerStateID::OFFICER_IDLE);

	// もし目的地に到達していたら処理を終了
	if (_arrayCount >= _routeList.size())
	{

		// 過去の位置を保存
		ObjectManager& objectManager = ObjectManager::Instance();
		character->pastRoom = static_cast<BaseSection*>(objectManager.Instance().FindPosObject(_routeList[_routeList.size() - 1], ObjectType::SECTION));
		character->SetPosition(_routeList.back());
		character->ChangeState(CharacterStateID::IDLE);

		return;
	}

	Vector2 current = character->GetPosition();
	Vector2 target = _routeList[_arrayCount];

	// まずx方向の移動を完了させる
	float dx = target.x - current.x;
	float distance = std::abs(dx);

	if (distance < 2.0f)
	{
		current.x = target.x;
		character->SetPosition(current);
		_arrayCount++;

		return;
	}

	// x移動を滑らかに進める
	float moveX = (dx / distance) * speed;
	current.x += moveX;

	// まだy移動しない
	current.y = target.y;

	character->SetPosition(current);
}

void CharacterStateMove::Enter(BaseCharacter* character)
{
	character->color = MOVE;
	_arrayCount = 0;
	character->stateID = CharacterStateID::MOVE;
}

void CharacterStateMove::Exit(BaseCharacter* character)
{
	character->color = IDLE;
	_routeList.clear();
}