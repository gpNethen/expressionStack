#include <cstdlib>
#include <iostream>
#include <cstring>
#include "Stack.h"
using namespace std;

void Stack :: push ( Item entry )
{
	data[used++] = entry;
}

Stack :: Item Stack :: pop ( )
{
	return data [--used];
}
Stack :: Item Stack :: peek ( )
{
	return data[used-1];
}

