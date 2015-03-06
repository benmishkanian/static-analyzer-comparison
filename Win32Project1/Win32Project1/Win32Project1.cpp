// Win32Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	// 1. Null Pointer Dereference
	int *p;
	p = NULL;
	*p = 3;
	return 0;
}

