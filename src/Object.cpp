#include "Object.h"

//Assigns a vector based location to the objects.
Object::Object(Vector vector)
{
	this->position = vector;
}

Object::~Object()
{

}

void Object::Position(Vector vector) { 
	this->position = vector; }
Vector Object::Position() { return this->position; }