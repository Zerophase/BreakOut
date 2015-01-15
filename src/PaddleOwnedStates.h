#ifndef PADDLE_OWNED_STATES_H
#define PADDLE_OWNED_STATES_H

#include "State.h"
#include "Object.h"
#include "Telegram.h"

class Paddle;

class PaddleGlobalState : public State<Paddle>
{
private:
	PaddleGlobalState() {}

	PaddleGlobalState(const PaddleGlobalState&);
	PaddleGlobalState &operator=(const PaddleGlobalState&);

public:
	static PaddleGlobalState *Instance();

	virtual void Enter(Paddle *paddle) {}
	virtual void Execute(Paddle *paddle);
	virtual void Exit(Paddle *paddle) {}
	virtual void OnMessage(Paddle* paddle, Telegram *telegram);
};

class HoldBall : public State<Paddle>
{
private:
	HoldBall() {}

	HoldBall(const HoldBall&);
	HoldBall &operator=(const HoldBall&);

public:
	static HoldBall *Instance();

	virtual void Enter(Paddle *paddle);
	virtual void Execute(Paddle *paddle);
	virtual void Exit(Paddle *paddle);
	virtual void OnMessage(Paddle* paddle, Telegram *telegram);
};

class FreeBall : public State<Paddle>
{
private:
	FreeBall() {}

	FreeBall(const FreeBall&);
	FreeBall &operator=(const FreeBall&);

public:
	static FreeBall *Instance();

	virtual void Enter(Paddle *paddle);
	virtual void Execute(Paddle *paddle);
	virtual void Exit(Paddle *paddle);
	virtual void OnMessage(Paddle* paddle, Telegram *telegram);
};
#endif // !PADDLE_OWNED_STATES_H
