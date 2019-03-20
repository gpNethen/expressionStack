#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>
#include <cstring>

static const int CAPACITY = 20;
class Stack
{
	public: 
    	typedef int Item;
    	Stack( ) { used = 0; };
    	void push ( Item entry );
    	Item pop ( );
    	int size ( ) { return used; }
    	bool empty ( ) { return used == 0; };
    	Item peek ( );
	private:
    	Item data[CAPACITY];
    	int used;
};
#endif
