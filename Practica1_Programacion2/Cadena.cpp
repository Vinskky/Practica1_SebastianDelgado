#include "..\Practica1_Programacion2\Cadena.h"

	Cadena::Cadena()
	{
		int size = 1;
		string = new char[size];
		char* string = '\0';
	}

	Cadena::Cadena(const char* a)
	{
		size = strlen(a) + 1;
		string = new char[size];
		strcpy_s(string, size, a);
	}

	Cadena::Cadena(const char* a, ...)
	{
		if (a != NULL)
		{
			static char buff1[4096];
			static va_list arg;

			va_start(arg, a);
			int res = vsprintf_s(buff1, 4096, a, arg);
			va_end(arg);

			if (res > 0)
			{
				size = res + 1;
				string = new char[size];
				strcpy_s(string, size, buff1);
			}

		}
	}

	Cadena::~Cadena()
	{
		delete[] string;
	}


	bool Cadena::operator == (const char* str)
	{
		if (str != NULL)
		{
			return  strcpy_s(string, size, str) == 0;
		}
		return false;
	}

	bool Cadena::operator ==(const Cadena& str)
	{
		return strcpy_s(string, size, str.string) == 0;
	}

	bool Cadena::operator !=(const char* str)
	{
		if (str != NULL)
		{
			return strcmp(string, str) != 0;
		}
		return false;
	}

	bool Cadena::operator !=(const Cadena& str)
	{
		return strcmp(string, str.string) != 0;
	}

	Cadena& Cadena::operator =(const char* str)
	{
		if (str != NULL)
		{
			if (strlen(str) + 1 > size)		//compare lenght of the two strings in case size is smaller than str redo size
			{
				delete[] string;
				Alloc(strlen(str) + 1);
			}
			else							//copy str to string
				strcpy_s(string, size, str);
		}
		else
		{
			Clear();
		}
		return (*this);
	}

	Cadena& Cadena::operator =(const Cadena& str)
	{
		if (strlen(str.string) + 1 > size)
		{
			delete[] string;
			Alloc(strlen(str.string) + 1);
		}
		return (*this);
	}

	Cadena& Cadena::operator +=(const char* str)
	{
		if (str != NULL)
		{
			if (size <= (strlen(str) + strlen(string)))					//if size smaller than the length of srt and string do
			{
				char* aux_string = new char [strlen(string)+1];			//create an auxiliar string to copy string
				strcpy_s(aux_string, strlen(string), string);
				Alloc((strlen(str) + 1) + strlen(string));				//this function delete string and redo size
				strcpy_s(string, strlen(aux_string), aux_string);		//copy the aux string to string
				strcat_s(string, size, str);							//function to add to string str
				delete[] aux_string;									//dele aux string from memory
			}
			else
			{
				strcat_s(string, size, str);
			}
			return (*this);
		}
		else
		{
			return (*this);
		}

	}

	Cadena& Cadena::operator +=(const Cadena& str)
	{
		if (size <= (strlen(str.string) + strlen(string)))
		{
			char* aux_string = new char[strlen(string) + 1];
			strcpy_s(aux_string, strlen(string), string);
			Alloc((strlen(str.string) + 1) + strlen(string));
			strcpy_s(string, strlen(aux_string), aux_string);
			strcat_s(string, size, str.string);
			delete[] aux_string;
		}
		else
		{
			strcat_s(string, size, str.string);
		}
		return (*this);

	}


void Cadena::Clear()
{
	delete[] string;
	int size = 1;
	string = new char[size];

}

char* Cadena::GetString()
{
	return string;
}

int Cadena::Length()
{
	return strlen(string);
}

int Cadena::Capacity()
{
	return size;
}

const void Cadena::Alloc(const int i)
{
	delete[] string;
	string = new char[i + 1];
}
