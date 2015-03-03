#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Practica1_Programacion2\Punto2d.h"
#include "..\Practica1_Programacion2\Cadena.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//--------------------------------
		//--Unit test class Punto2d ------
		//--------------------------------

		//SetZero method
		TEST_METHOD(TestMethod1)
		{
			Punto2d a;
			a.SetZero();
			Assert::IsTrue(a.x == 0.0 && a.y == 0.0);
		}

		TEST_METHOD(TestMethod2) //isZero method
		{
			Punto2d a;
			a.IsZero();

			if (a.x == 0 && a.y == 0)
				Assert::IsTrue(a.x == 0 && a.y == 0);
			else
				Assert::IsTrue(a.x != 0 && a.y != 0);
		}
		TEST_METHOD(TestMethod3) //negatePos method
		{
			Punto2d a1;
			Punto2d a2;
			a1.x = 1;
			a1.y = 1;
			a2.x = -1;
			a2.y = -1;
			
			Assert::IsTrue(a1.x == a2.x && a1.y == a2.y);
		}
		TEST_METHOD(TestMethod4) //distanceTo method
		{
			Punto2d a1;
			Punto2d& ra1 = a1;
			Punto2d a2;
			a1.x = 6;
			a1.y = 5;
			a2.x = 2;
			a2.y = 2;

			Assert::IsTrue(a2.DistanceTo(ra1) == 5);
		}
		TEST_METHOD(TestMethod5) //operator +
		{
			Punto2d a1;
			Punto2d a2;
			Punto2d& ra2 = a2;
			Punto2d a3;
			a1.x = 4;
			a1.y = 4;
			a2.x = 3;
			a2.y = 3;
			a3 = a1 + ra2;

			Assert::IsTrue(a3 == a1.operator+ (ra2));
		}
		TEST_METHOD(TestMethod6) //operator +=
		{


		}
		TEST_METHOD(TestMethod7) //operator -
		{
			Punto2d a1;
			Punto2d a2;
			Punto2d& ra2 = a2;
			Punto2d a3;
			a1.x = 4;
			a1.y = 4;
			a2.x = 3;
			a2.y = 3;
			a3 = a1 - ra2;

			Assert::IsTrue(a3 == a1.operator- (ra2));
		}
		TEST_METHOD(TestMethod8) //operator -=
		{


		}
		TEST_METHOD(TestMethod9) //operator ==
		{
			Punto2d a1;
			Punto2d a2;
			a1.x = 1;
			a1.y = 1;
			a2.x = 1;
			a2.y = 1;

			Assert::IsTrue(a1.operator == (a2));
		}
		TEST_METHOD(TestMethod10) //operator !=
		{
			Punto2d a1;
			Punto2d a2;
			a1.x = 1;
			a1.y = 1;
			a2.x = 2;
			a2.y = 2;

			Assert::IsTrue(a1.operator != (a2));
		}

		//--STRING UNIT TEST---------------------------------------------------
		TEST_METHOD(TestMethod11) //empty constructor
		{
			Cadena str;

			Assert::IsTrue(str == "");
		}
		TEST_METHOD(TestMethod12) //constructor ( _string, ...)
		{
			Cadena str;
			str.string = ("Hola");

			Assert::IsTrue(str == "Hola");
		}
		TEST_METHOD(TestMethod13) //operator == (with reference)
		{
			Cadena str;
			str.string = ("Hola");
			Cadena& rstr = str;
			Cadena str2;
			str2.string = ("Hola");

			Assert::IsTrue(rstr.operator == (str2));
		}
		TEST_METHOD(TestMethod14) //operator == (with char*)
		{
			Cadena str;
			str.string = ("Hola");
			Cadena str2;
			str2.string = ("Hola");

			Assert::IsTrue(str.operator == (str2));
		}
		TEST_METHOD(TestMethod15) //operator = (with reference)
		{
			Cadena str;
			str.string = ("Hola");
			Cadena& rstr = str;
			Cadena str2;
			str2.string = ("Hola mundo");
			str2 = rstr;

			Assert::AreEqual(str2.Length(), str.Length());
		}
		TEST_METHOD(TestMethod16) //operator = (with char*)
		{
			Cadena str;
			str.string = ("Hola");
			Cadena str2;
			str2.string = ("Hola mundo");
			str2 = str;

			Assert::AreEqual(str2.Length(), str.Length());
		}
		TEST_METHOD(TestMethod17) //operator != (with reference)
		{
			Cadena str;
			str.string = ("Hola");
			Cadena& rstr = str;
			Cadena str2;
			str2.string = ("Hola mundo");

			Assert::IsTrue(rstr.operator != (str2) != 0);
		}
		TEST_METHOD(TestMethod18) //operator != (with char*)
		{
			Cadena str;
			str.string = ("Hola");
			Cadena str2;
			str2.string = ("Hola mundo");

			Assert::IsTrue(str.operator != (str2) != 0);
		}
		TEST_METHOD(TestMethod19) //operator += (with reference)
		{


		}
		TEST_METHOD(TestMethod20) //operator += (with char*)
		{
			Cadena str;
			str.string = ("Hola");
			Cadena str2;
			str2.string = ("mundo");

			Assert::IsTrue(str.operator += (str2) == "Hola mundo");
		}
		TEST_METHOD(TestMethod21) //Clear unit test
		{
			Cadena str;
			str.string = ("Hola");
			Cadena str2;
			str.Clear();

			Assert::IsTrue(str == str2);
		}
		TEST_METHOD(TestMethod22) //Alloc unit test
		{
			Cadena str;
			str.string = ("Hola");
			str.Alloc(5);

			Assert::IsTrue((strlen(str.string) + 1) == 6);
		}
		TEST_METHOD(TestMethod23) //Length
		{
			Cadena str;
			str.string = ("Hola");

			Assert::IsTrue(str.Length() == 5);
		}
		TEST_METHOD(TestMethod24) //getString
		{
			Cadena str;
			str.string = ("Hola");

			Assert::IsTrue(str.GetString() == "Hola");
		}

	};
}