#ifndef BALL_H
#define BALL_H

#include "Object.h"
#include "BlockManager.h"
#include "Node.h"
#include "CollidableRect.h"
#include "StateMachine.h"
#include "BallOwnedStates.h"
#include "Telegram.h"

//A ball with speed, and methods for handling interaction with other objects on screen
//and the sides of the window.

template <class Object> class State;

class Ball : public Object 
{
	private:
		StateMachine<Ball> *stateMachine;

		bool waitForBounce;
		int bounceTimer;
		int iD;

		Vector bounceOnBlock(Ball &ball);
		
		Vector steeringForce;

		NodeMethods nodeMethods;

	public:
		Ball(Vector vector, float radius);
		Ball()
		{
		}

		~Ball();

		int GetID() { return iD; }

		Vector speed;
		Vector desiredSpeed;
		Vector target;

		Vector GetSteeringForce() { return steeringForce; }
		void SetSteeringForce(Vector toAgent) 
		{ 
			if (toAgent == Vector(0, 0))
				steeringForce = toAgent;
			else
				steeringForce = steeringForce + (Normalize(toAgent) / sqrtf(toAgent.x * toAgent.x + toAgent.y * toAgent.y));
		
		}

		static int count;

		//Ball &operator=(Ball &ball);

		virtual void Update();
		virtual void HandleMessage(Telegram *telegram);

		Ball *Clone(Vector newBallpos);

		StateMachine<Ball> *GetFSM() const { return stateMachine; }

		virtual void Draw();

		Vector Bounce(Ball &ball, float width, float height);
		Vector BounceOnPaddle(Ball &ball, CollidableRect &paddle);
		Vector BounceOnWall(Ball &ball, float width, float height);
		void X(float x);
		float X();

		void Y(float y);
		float Y();

		void Radius(float radius);
		float Radius();

		Vector Speed();
		bool BallUnlocked;

		Vector Move();
		float radius;
		bool Flash;
};
#endif