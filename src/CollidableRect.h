#ifndef COLLIDABLERECT_H
#define COLLIDABLERECT_H

#include "Object.h"
#include "GenericObject.h"

//Gives the blocks and rects some shared parameters.
class CollidableRect : public Object
{
	protected:
		Vector vector;
		
	public:
		CollidableRect(Vector vector, float width, float height);
		CollidableRect(){}
		~CollidableRect();
		
		float height;
		float width;
		void Height(float height);
		float Height();

		void Width(float width);
		float Width();
};

#endif