#ifndef BALL_OWNED_STATES_H
#define BALL_OWNED_STATES_H

#include "State.h"
#include "Telegram.h"

class Ball;

class BallGlobalState : public State<Ball>
{
private:
	BallGlobalState () {}

	BallGlobalState(const BallGlobalState&);
	BallGlobalState &operator=(const BallGlobalState&);

public:
	static BallGlobalState *Instance();

	virtual void Enter(Ball *ball) {}
	virtual void Execute(Ball *ball);
	virtual void Exit(Ball *ball) {}
	virtual void OnMessage(Ball* ball, Telegram *telegram);
};

class BounceOnWall : public State<Ball>
{
private:
	BounceOnWall () {}

	BounceOnWall(const BounceOnWall&);
	BounceOnWall &operator=(const BounceOnWall&);

public:
	static BounceOnWall *Instance();

	virtual void Enter(Ball *ball);
	virtual void Execute(Ball *ball);
	virtual void Exit(Ball *ball);
	virtual void OnMessage(Ball* ball, Telegram *telegram);
};

class OnPaddle : public State<Ball>
{
private:
	OnPaddle() {}

	OnPaddle(const OnPaddle&);
	OnPaddle &operator=(const OnPaddle&);

public:
	static OnPaddle *Instance();

	virtual void Enter(Ball *ball);
	virtual void Execute(Ball *ball);
	virtual void Exit(Ball *ball);
	virtual void OnMessage(Ball* ball, Telegram *telegram);
};

class Free : public State<Ball>
{
private:
	Free(){}

	Free(const Free&);
	Free &operator=(const Free&);

public:
	static Free *Instance();

	virtual void Enter(Ball *ball);
	virtual void Execute(Ball *ball);
	virtual void Exit(Ball *ball);
	virtual void OnMessage(Ball* ball, Telegram *telegram);
};

//class BounceOnBlock : public State<Block>
//{
//
//};
#endif