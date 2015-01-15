#include "BallOwnedStates.h"
#include "State.h"
#include "Ball.h"
#include "testApp.h"
#include "Object.h"
#include "Functor.h"
#include <typeinfo>

BallGlobalState *BallGlobalState::Instance()
{
	static BallGlobalState instance;
	return &instance;
}

void BallGlobalState::Execute(Ball *ball)
{
}

void BallGlobalState::OnMessage(Ball* ball, Telegram *telegram)
{

}

BounceOnWall *BounceOnWall::Instance()
{
	static BounceOnWall instance;
	return &instance;
}

void BounceOnWall::Enter(Ball *ball)
{

}

void BounceOnWall::Execute(Ball *ball)
{

}

void BounceOnWall::Exit(Ball *ball)
{

}

void BounceOnWall::OnMessage(Ball* ball, Telegram *telegram)
{

}

OnPaddle *OnPaddle::Instance()
{
	static OnPaddle instance;
	return &instance;
}

void OnPaddle::Enter(Ball *ball)
{

}

void OnPaddle::Execute(Ball *ball)
{
	if(ofGetKeyPressed(32))
	{
		Functor::Send();
		ball->GetFSM()->ChangeState(Free::Instance());		
	}
}

void OnPaddle::Exit(Ball *ball)
{

}

void OnPaddle::OnMessage(Ball* ball, Telegram *telegram)
{
	
	if (typeid(*telegram->message) == typeid(Paddle))
		ball->position.x = (((Paddle*) (telegram)->message)->position.x + 50);
}

Free *Free::Instance()
{
	static Free instance;
	return &instance;
}

void Free::Enter(Ball *ball)
{

}

void Free::Execute(Ball *ball)
{
	ball->position = ball->Move();
	
	ball->BounceOnWall(*ball, 1280, 768);
	Functor::Send();
}

void Free::Exit(Ball *ball)
{

}

void Free::OnMessage(Ball* ball, Telegram *telegram)
{

}