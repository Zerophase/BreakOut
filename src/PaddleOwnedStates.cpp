#include "PaddleOwnedStates.h"
#include "State.h"
#include "Paddle.h"
#include "testApp.h"
#include "Functor.h"
#include "Telegram.h"
#include "testApp.h"

PaddleGlobalState *PaddleGlobalState::Instance()
{
	static PaddleGlobalState instance;
	return &instance;
}

void PaddleGlobalState::Execute(Paddle *paddle)
{
	if (ofGetKeyPressed(356))
		paddle->Position(paddle->Position() + paddle->Move(356, 1280));
	else if (ofGetKeyPressed(358))
		paddle->Position(paddle->Position() + paddle->Move(358, 1280));
}

void PaddleGlobalState::OnMessage(Paddle* paddle, Telegram *telegram)
{

}

HoldBall *HoldBall::Instance()
{
	static HoldBall instance;
	return &instance;
}

void HoldBall::Enter(Paddle *paddle)
{

}

void HoldBall::Execute(Paddle *paddle)
{
	Functor::Send();
	if (ofGetKeyPressed(32))
		paddle->GetFSM()->ChangeState(FreeBall::Instance());
}

void HoldBall::Exit(Paddle *paddle)
{

}

void HoldBall::OnMessage(Paddle* paddle, Telegram *telegram)
{

}

FreeBall *FreeBall::Instance()
{
	static FreeBall instance;
	return &instance;
}

void FreeBall::Enter(Paddle *paddle)
{

}

void FreeBall::Execute(Paddle *paddle)
{

}

void FreeBall::Exit(Paddle *paddle)
{

}

void FreeBall::OnMessage(Paddle* paddle, Telegram *telegram)
{
	if (typeid(*telegram->message) == typeid(Ball))
	{
		Ball *ball = ((Ball*) (telegram)->message);
		ball->BounceOnPaddle(*ball, *paddle);
	}
		
}
