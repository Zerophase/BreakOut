#ifndef OBJECT_H
#define OBJECT_H
#include "Vector2D.h"
#include "Telegram.h"

//Gives all objects a sense of position.
class Object
{
	public:
		Object(Vector vector);
		Object() {}

		virtual ~Object();
		virtual void Update() = 0;
		virtual void HandleMessage(Telegram *telegram) = 0;

		Vector position;

		void Position(Vector vector);
		Vector Position();
};

#endif
