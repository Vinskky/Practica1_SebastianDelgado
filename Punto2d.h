#include <stdio.h>
#include <math.h>

class Punto2d
{
	private:
		float x, y;
		
	public:
		Punto2d(){
			x = 0.0;
			y = 0.0;
		}

		Punto2d operator -(const Punto2d& a)const
		{
			Punto2d result;
			 result.x = x - a.x;
			 result.y = y - a.y;
			return result;
		}
		Punto2d operator + (const Punto2d& a)const
		{
			Punto2d result;
			result.x = x + a.x;
			result.y = y + a.y;
			return result;
		}
		Punto2d& operator -=(const Punto2d& a)
		{
			x -= a.x;
			y -= a.y;
			return (*this);
		}
		Punto2d& operator +=(const Punto2d& a)
		{
			x += a.x;
			y += a.y;
			return (*this);
		}
		Punto2d operator = (const Punto2d& a)
		{
			x = a.x;
			y = a.y;
			return (*this);
		}
		bool operator == (const Punto2d& a)const
		{
			if (x == a.x && y == a.y)
				return true;
			return false;
		}
		bool operator !=(const Punto2d& a)const
		{
			if (x != a.x || y != a.y)
				return true;
			return false;
		}
		bool isZero();
		Punto2d& setZero();
		float distanceTo(Punto2d a);
};

bool Punto2d::isZero()
{
	if (x == 0.0 && y == 0.0)
		return true;
	return false;
}

Punto2d& Punto2d::setZero()
{
	x = 0.0;
	y = 0.0;
	return (*this);
}

float distanceTo(Punto2d a)
{
	return sqrtf(pow(a.x - x, 2) + pow(a.y - y, 2));
}