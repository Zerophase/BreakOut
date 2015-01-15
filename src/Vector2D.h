#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

//Vector class
class Vector
{
	public:
		float x, y;

		Vector();
		Vector(float x, float y);

		bool operator==(const Vector &v) const;
		bool operator!=(const Vector &v) const;
		bool operator!=(const float &f) const;
		bool operator>=(const Vector &v) const;
		//TODO check if operator returns true on <=
		bool operator<=(const Vector &v) const;
		bool operator<(const Vector &v) const;
		bool operator>(const Vector &v) const;

		inline float Length() const;
		inline void Nomralize();
		friend Vector Normalize(const Vector &v);

		friend Vector operator+(const Vector &v1, const Vector &v2);
		friend Vector operator+(const Vector &v1, float value);
		friend Vector operator+(float value, const Vector &v2);

		friend Vector operator-(const Vector &v1, const Vector &v2);
		friend Vector operator-(const Vector &v1, float value);
		friend Vector operator-(float value, const Vector &v2);

		friend Vector operator/(const Vector &v, float value);

		friend Vector operator*(const Vector &v1, const Vector &v2);
		friend Vector operator*(const Vector &v1, float value);
		friend Vector operator*(float value, const Vector &v2);

		friend Vector operator*=(const Vector &v1, const Vector &v2);
		friend Vector operator*=(const Vector &v1, float value);
		friend Vector operator*=(float value, const Vector &v2);

		friend Vector operator+=(const Vector &v1, const Vector &v2);
		friend Vector operator+=(const Vector &v1, int value);
		friend Vector operator+=(int value, const Vector &v2);

		friend Vector operator-=( Vector &v1, Vector &v2);
		friend Vector operator-=(const Vector &v1, int value);
		friend Vector operator-=(int value, const Vector &v2);

		friend Vector operator/=(const Vector &v, const float &value);
		//Could probably remove
		//friend ostream& operator<<(ostream &out, Vector &v);
};

#endif