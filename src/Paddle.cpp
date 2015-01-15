#include "Paddle.h"
#include "testApp.h"

Paddle::Paddle(Vector paddleVector, float width, float height)
	:CollidableRect(paddleVector, width, height)
{
	stateMachine = new StateMachine<Paddle>(this);
	stateMachine->SetCurrentState(HoldBall::Instance());
	stateMachine->SetGlobalState(PaddleGlobalState::Instance());

	this->height = height;
	this->width = width;
}

Paddle::~Paddle()
{

}

void Paddle::Update()
{
	stateMachine->Update();
}

void Paddle::HandleMessage(Telegram *telegram)
{
	stateMachine->HandleMessage(telegram);
}

void Paddle::Draw()
{
	ofSetColor(100, 100, 100);
	ofRect(this->Position().x, this->Position().y, this->width, this->height);
}

//Causes the paddle to move left or right on left or right arrow keys presses respectively.
Vector Paddle::Move(int key, float width)
{
	//stops paddle from going off screen.
	if (this->position.x <= 0)
	{
		this->position.x = this->position.x + 10;
	}
	//TODO pinpoint precise location of paddle drawing origin.
	else if((this->position.x + this->width) >= width)
	{
		this->position.x = this->position.x - 10;
	}

	//Moves paddle from left to right
	//left key
	Vector vector;
	if (key == 356)
	{
		vector = Vector(-1, 0);
	}

	//right key
	if (key == 358)
	{
		vector = Vector(1,0);
	}

	speed = Vector(15, 0);

	return (vector * speed);
}

//Locks the ball to the paddle until the spacebar is pressed.
Vector Paddle::LockBall(Ball &ball, int key)
{
	if (key != 32 
		&& (ball.position.x >= (this->position.x + 50)
		|| ball.position.x <= (this->position.x + 100)))
	{
		if (!ball.BallUnlocked)
		{
			ball.position.x = (this->position.x + 50);
		}
	}
	else
	{
		ball.BallUnlocked = true;
	}
		

	return ball.position;
}