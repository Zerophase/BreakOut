#include "Ball.h"
#include "testApp.h"

int Ball::count = 0;

//assigns the ball some default values.
Ball::Ball(Vector ballVector, float radius)
	: Object(ballVector) 
{

	stateMachine = new StateMachine<Ball>(this);
	
	if (this->count == 0)
	{
		iD = 0;
		stateMachine->SetCurrentState(OnPaddle::Instance());
	}
		
	else if (this->count > 0)
	{
		iD++;
		stateMachine->SetCurrentState(Free::Instance());
	}
		

	stateMachine->SetGlobalState(BallGlobalState::Instance());

	count++;

	this->steeringForce = Vector(0, 0);
	this->radius = radius;
	this->speed = Vector(10, 10);
	this->BallUnlocked = false;
	this->Flash = false;
	this->waitForBounce = false;
	this->bounceTimer = 0;
}

Ball::~Ball()
{
	
}


void Ball::Update()
{
	stateMachine->Update();
}

void Ball::HandleMessage(Telegram *telegram)
{
	stateMachine->HandleMessage(telegram);
}

Ball *Ball::Clone(Vector newBallPos)
{
	return new Ball(newBallPos, this->radius);
}

void Ball::Draw()
{
	ofSetColor(100, 100, 100);
	ofCircle(this->position.x, this->position.y, this->Radius());
}

//Moves the ball when it has been released from the paddle
Vector Ball::Move()
{
	if(steeringForce == Vector(0, 0))
		this->position -= this->speed;
	else
		this->position -= steeringForce * this->speed;

	return this->position;
}

//responsible for making the ball bounce off of walls.
Vector Ball::Bounce(Ball &ball, float width, float height)
{
	ball.position = bounceOnBlock(ball);

	return ball.position;
}

Vector Ball::BounceOnPaddle(Ball &ball,  CollidableRect &paddle)
{

	//TODO check if ball.position.x needs ball.radius added to it
	//Order left, top, right
	if (ball.position.x >= (paddle.position.x + (paddle.width /2)) &&
			(ball.position.y + (ball.radius / 2)) >= paddle.position.y &&
			(ball.position.x + (ball.radius / 2)) <= (paddle.position.x + paddle.width)
			)
	{
		//TODO need to make ball not get stuck at start, and remove this.
		ball.position = ball.position - 40;
		ball.speed.y = ball.speed.y * -1;
		ball.position = ball.position + ball.speed;

		//TODO remove flash from bottom of wall.
		ball.Flash = false;
	}
	else if(ball.position.x >= paddle.position.x &&
			ball.position.y + (ball.radius) >= paddle.position.y &&
			ball.position.x + (ball.radius) <= (paddle.position.x + (paddle.width / 2)))
	{
		ball.position.y = ball.position.y - 40;
		ball.position.x = ball.position.x + 40;
		ball.speed = ball.speed * -1;
		ball.position = ball.position + ball.speed;

		ball.Flash = false;
	}

	return ball.position;
}

//Makes the ball bounce off of blocks, and tells the screen it is time to start flashing.
Vector Ball::bounceOnBlock(Ball &ball)
{
	//THESE are all old means of checking. Keep as reference until collision works close enough.
	/*(ball.position.x + (ball.radius / 2)) >= (currentBlock->BlockNode.position.x)
		&& (ball.position.y + (ball.radius / 2)) >= (currentBlock->BlockNode.position.y )
		&& ((ball.position.x) <= 
		currentBlock->BlockNode.position.x + currentBlock->BlockNode.width / 2)
		&& (ball.position.y) <=
		(currentBlock->BlockNode.position.y + currentBlock->BlockNode.height)*/


	/*(ball.position.x ) <= (currentBlock->BlockNode.position.x + currentBlock->BlockNode.width) &&
			ball.position.x >= (currentBlock->BlockNode.position.x) &&
			(ball.position.y) <= (currentBlock->BlockNode.position.y + currentBlock->BlockNode.height) &&
			ball.position.y >= currentBlock->BlockNode.position.y*/
	//Order of checks on block bottom, right, left, top
	//TODO test top and left side collision
	//TODO make block send ball down depending on bounce angle.
	
	ball.speed.y *= -1;
	ball.position = ball.position + ball.speed;

	return ball.position;
}
//Causes the ball to bounce on walls, and lets the screen know it can stop flashing.
Vector Ball::BounceOnWall(Ball &ball, float width, float height)
{
	//TODO Remove bounce from bottom of screen.
	//Balls getting stuck on bottom and top corners.  
	//The ball is infinitely bouncing between the intersection of these sides.
	//Need to change balls bounce based on orientation.
	// if ball is traveling up towards Ist quadrant ball should be reflected
	//towards 2nd.  If ball is traveling down towards 4 quadrant ball should be reflected towards
	//3rd and vice versa.
	//Still flying off screen from top right corners.
	if ((ball.position.x + (ball.radius)) >= width 
		|| (ball.position.x /*- (ball.radius)*/) <= 0
		|| (ball.position.y + (ball.radius)) >= height 
		|| (ball.position.y - (ball.radius)) <= 0)
	{
		if( (ball.position.x - ball.radius) <= 0 &&
					(ball.position.y + ball.radius) >= height)
		{
			ball.position.x = ball.position.x + 60;
			ball.position.y = ball.position.y - 60;
		}
		//TODO implement check for top right corner.
		else if ((ball.position.x + ball.radius) >= width &&
					(ball.position.y - ball.radius) <= 0) 
		{
			ball.position.x = ball.position.x - 60;
			ball.position.y = ball.position.y + 60;
		}
		else if ((ball.position.x + (ball.radius)) >= width
			|| (ball.position.y + (ball.radius)) >= height)
		{
			ball.position = ball.position - 60;
		}
		else
			ball.position = ball.position + 60;
		 
		//Might be able to remove.
		if(!ball.waitForBounce)
			ball.waitForBounce = true;

		if (ball.position.y >= (ball.position.y + ball.speed.y))
		{
			ball.speed.y = ball.speed.y * -1;
		}
		
		if(ball.position.y <= (ball.position.y + ball.speed.y))
		{
			ball.speed.x = ball.speed.x * -1;
		}

		if ((ball.position.x - ball.radius) <= 0)
		{
		//	ball.speed.x = ball.speed.x * -1;
		}
		ball.position = ball.position + ball.speed;
		ball.Flash = false;
	}
	return ball.position;
}



void Ball::Radius(float radius) { this->radius = radius; }
float Ball::Radius() { return this->radius; }

Vector Ball::Speed() { return this->speed; }