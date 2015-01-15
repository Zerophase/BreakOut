#ifndef CUSTOMMATH_H
#define CUSTOMMATH_H

#include <stdlib.h>

inline float RandomFloat(float a, float b)
{
	float random = ((float) rand()) / (float) RAND_MAX;
	float difference = b - a;
	float r = random * difference;
	return a + r;
}
#endif // !CUSTOMMATH_H
