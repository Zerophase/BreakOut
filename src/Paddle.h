#ifndef PADDLE_H
#define PADDLE_H

#include "CollidableRect.h"
#include "Ball.h"
#include "StateMachine.h"
#include "PaddleOwnedStates.h"
#include "Telegram.h"

struct Telegram;
//A paddle meant to hit the ball.
//I ran out of time before I could implement the paddle.
//TODO implement paddle
class Paddle : public CollidableRect
{
	public:
		Paddle(Vector paddleVector, float width, float height);
		Paddle(){}
		~Paddle();

		virtual void Update();
		virtual void HandleMessage(Telegram *telegram);

		virtual void Draw();

		StateMachine<Paddle> *GetFSM() const { return stateMachine; }

		Vector Move(int key, float width);
		Vector LockBall(Ball &ball, int key);

	private:
		StateMachine<Paddle> *stateMachine;

		Vector speed;
};

#endif