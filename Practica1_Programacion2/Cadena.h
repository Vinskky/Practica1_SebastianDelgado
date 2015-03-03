#ifndef _Cadena_H_
#define _Cadena_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <wtypes.h>

#define TMP_STRING_SIZE 4091

class Cadena
{
public:
	int unsigned size;
	char* string;

	Cadena();

	Cadena(const char* str);

	Cadena(const char* a, ...);

	~Cadena();

	bool operator == (const char* str);

	bool operator ==(const Cadena& str);

	bool operator !=(const char* str);

	bool operator !=(const Cadena& str);

	Cadena& operator =(const char* str);

	Cadena& operator =(const Cadena& str);

	Cadena& operator +=(const char* str);

	Cadena& operator +=(const Cadena& str);

	int Length();

	int Capacity();

	char* GetString();

	void Clear();

	const void Alloc(const int i);

};

#endif _Cadena_H_