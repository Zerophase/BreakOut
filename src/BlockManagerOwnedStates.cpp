#include "BlockManagerOwnedStates.h"
#include "BlockManager.h"
#include "State.h"
#include "testApp.h"
#include "Object.h"
#include "Functor.h"
#include <typeinfo>


CollisionWithBall *CollisionWithBall::Instance()
{
	static CollisionWithBall instance;
	return &instance;
}

void CollisionWithBall::Enter(BlockManager *blockManager)
{

}

void CollisionWithBall::Execute(BlockManager *blockManager)
{
	blockManager->HandleCollision();
}

void CollisionWithBall::Exit(BlockManager *blockManager)
{

}

void CollisionWithBall::OnMessage(BlockManager *blockManager, Telegram *telegram)
{
	if (typeid(*telegram->message) == typeid(Ball)
		&& blockManager->theBalls.size() < ((Ball*) (telegram)->message)->count)
		blockManager->theBalls.push_back(((Ball*) (telegram)->message));
}