#include "CollidableRect.h"

//Gives the rect a height and width
CollidableRect::CollidableRect(Vector collidableVector, float width, float height)
	:Object(collidableVector)
{
	this->height = height;
	this->width = width;
}

CollidableRect::~CollidableRect()
{
	
}



void CollidableRect::Height(float height) { this->height = height; }
float CollidableRect::Height() { return this->height; }

void CollidableRect::Width(float width) { this->width = width; }
float CollidableRect::Width() { return this->width; }