#include "Punto2d.h"


	Punto2d::Punto2d()
	{
		x = 0.0;
		y = 0.0;
	}

	Punto2d Punto2d::operator -(const Punto2d& a)const
	{
		Punto2d result;
		result.x = x - a.x;
		result.y = y - a.y;
		return result;
	}

	Punto2d Punto2d::operator + (const Punto2d& a)const
	{
		Punto2d result;
		result.x = x + a.x;
		result.y = y + a.y;
		return result;
	}

	Punto2d& Punto2d::operator -=(const Punto2d& a)
	{
		x -= a.x;
		y -= a.y;
		return (*this);
	}

	Punto2d& Punto2d::operator +=(const Punto2d& a)
	{
		x += a.x;
		y += a.y;
		return (*this);
	}

	Punto2d Punto2d::operator = (const Punto2d& a)
	{
		x = a.x;
		y = a.y;
		return (*this);
	}

	bool Punto2d::operator == (const Punto2d& a)const
	{
		if (x == a.x && y == a.y)
			return true;
		return false;
	}

	bool Punto2d::operator !=(const Punto2d& a)const
	{
		if (x != a.x || y != a.y)
			return true;
		return false;
	}


bool Punto2d::IsZero()
{
	if (x == 0.0 && y == 0.0)
		return true;
	return false;
}

Punto2d& Punto2d::SetZero()
{
	x = 0.0;
	y = 0.0;
	return (*this);
}

float Punto2d::DistanceTo(Punto2d a)
{
	return sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y));
}
