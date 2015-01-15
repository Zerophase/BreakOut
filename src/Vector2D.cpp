#include "Vector2D.h"
#include <cmath>

//Vector class with methods for performing math directly on vectors.
//Most of the -=, +=, and *= don't work.
//I just got the one I used working.
Vector::Vector()
{
	this->x = 0;
	this->y = 0;
}

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

bool Vector::operator==(const Vector &v) const
{
	return ((x == v.x) && (y == v.y));
}

bool Vector::operator!=(const Vector &v) const
{
	return (!((*this) == v));
}

bool Vector::operator!=(const float &f) const
{
	return ((*this).x != f && (*this).y != f);
}

bool Vector::operator>=(const Vector &v) const
{
	return ((x >= v.x) && (y >= v.y));
}

bool Vector::operator<=(const Vector &v) const
{
	return (!((*this) >= v));
}

bool Vector::operator<(const Vector &v) const
{
	return ((x < v.x) && ( y < v.y));
}

bool Vector::operator>(const Vector &v) const
{
	return ((x > v.x) && ( y > v.y));
}

float Vector::Length() const
{
	return sqrtf(x * x + y * y);
}

void Vector::Nomralize()
{
	float vectorLength = this->Length();

	this->x /= vectorLength;
	this->y /= vectorLength;
}

Vector Normalize(const Vector &v)
{
	Vector vec = v;

	float vectorLength = vec.Length();

	vec.x /= vectorLength;
	vec.y /= vectorLength;

	return vec;
}

Vector operator+(const Vector &v1, const Vector &v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y);
}

Vector operator+(const Vector &v1, float value)
{
	return Vector(v1.x + value, v1.y + value);
}

Vector operator+(float value, const Vector &v2)
{
	return Vector(value + v2.x, value + v2.y);
}

Vector operator-(const Vector &v1, const Vector &v2)
{
	return Vector(v1.x - v2.x, v1.y - v2.y);
}

Vector operator-(const Vector &v1, float value)
{
	return Vector(v1.x - value, v1.y - value);
}

Vector operator-(float value, const Vector &v2)
{
	return Vector(value - v2.x, value - v2.y);
}

Vector operator/(const Vector &v, float value)
{
	Vector result(v);
	result.x /= value;
	result.y /= value;

	return result;
}

Vector operator/=(const Vector &v, const float &value)
{
	v.x / value;
	v.y / value;

	return v;
}

Vector operator*(const Vector &v1, const Vector &v2)
{
	return Vector(v1.x * v2.x, v1.y * v2.y);
}

Vector operator*(const Vector &v1, float value)
{
	return Vector(v1.x * value, v1.y * value);
}

Vector operator*(float value, const Vector &v2)
{
	return Vector(value * v2.x, value * v2.y);
}

Vector operator*=(const Vector &v1, const Vector &v2)
{
	return Vector(v1.x * v2.x, v1.y * v2.y);
}

Vector operator*=(const Vector &v1, float value)
{
	return Vector(v1.x * value, v1.y * value);
}

Vector operator*=(float value, const Vector &v2)
{
	return Vector(value * v2.x, value * v2.y);
}

Vector operator+=(const Vector &v1, const Vector &v2)
{
	Vector vec;
	vec.x = v1.x + v2.x;
	vec.y = v1.y + v2.y;
	
	return vec;
	//return Vector(v1.x + v2.x, v1.y + v2.y);
}
Vector operator+=(const Vector &v1, float value)
{
	return Vector(v1.x + value, v1.y + value);
}

Vector operator+=(float value, const Vector &v2)
{
	return Vector(value + v2.x, value + v2.y);
}

//THis is the one I used.
Vector operator-=( Vector &v1,  Vector &v2)
{
	 v1.x = v1.x - v2.x; 
	 v1.y = v1.y - v2.y;
	 return Vector(v1.x, v1.y);
}
Vector operator-=(const Vector &v1, float value)
{
	return Vector(v1.x - value, v1.y - value);
}

Vector operator-=(float value, const Vector &v2)
{
	return Vector(value - v2.x, value - v2.y);
}

ostream& operator<<(ostream &out, Vector &v)
{
	out << "The vector is (" << v.x << ", " << v.y << ").";
	return out;
}