#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "IntStack.h"
#include "IntStack.cpp"
#include "CharStack.h"
#include "CharStack.cpp"
using namespace std;

void openInputFile ( ifstream& inputFile );
int apply( char optr, int opnd1, int opnd2 );

int main()
{
	ifstream inFile;            // The input file stream
	char ch;                    // Each char read
	Stack s;                    // Stack for evaluating expressions
	int op1;
	int op2;
	int val;
	
	openInputFile(inFile);      // Open the input file.
	inFile.get( ch );
	while ( !inFile.eof() )
	{
  		cout << "Expression: ";
		while ( ch >= ' ' )
		{
			if ( ch > ' ' )
  				cout << ch;
  			if ( isdigit(ch) )
  				s.push(ch-'0');
  			if ( ch == '+' || ch == '-' || ch == '/' || ch == '*' )
  			{
  				op2 = s.pop();
  				op1 = s.pop();
  				val = apply( ch, op1, op2 );
  				s.push ( val );
  			}
			inFile.get( ch );
  		}
		cout << endl;
		cout << "Result: " << s.pop() << endl << endl;
		inFile.get(ch);
  	}
	inFile.close();             // Close the input file.

	return EXIT_SUCCESS;
}

void openInputFile ( ifstream &inputFile )
{
	char inputFileName[80];

	do
	{ inputFile.clear();
    	cout << "Enter input file name: ";
    	cin >> inputFileName;
    	inputFile.open(inputFileName);
    	cout << endl;
  	} while ( inputFile.fail() );
}

int apply ( char optr, int opnd1, int opnd2)
{
	switch( optr )
	{
		case '+':
			return (opnd1 + opnd2);
			break;
		case '-':
			return (opnd1 - opnd2);
			break;
		case '*':
			return (opnd1 * opnd2);
			break;
		case '/':
			return (opnd1 / opnd2);
			break;
		default:
			;
	}
}
