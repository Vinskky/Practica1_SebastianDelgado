#ifndef _Punto2d_H_
#define _Punto2d_H_

#include <stdio.h>
#include <math.h>

class Punto2d
{
public:
	float x, y;

	Punto2d();

	Punto2d operator -(const Punto2d& a)const;

	Punto2d operator + (const Punto2d& a)const;

	Punto2d& operator -=(const Punto2d& a);

	Punto2d& operator +=(const Punto2d& a);

	Punto2d operator = (const Punto2d& a);

	bool operator == (const Punto2d& a)const;

	bool operator !=(const Punto2d& a)const;

	bool IsZero();

	Punto2d& SetZero();

	float DistanceTo(Punto2d a);

};

#endif _Punto2d_H_