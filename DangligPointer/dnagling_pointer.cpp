#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the Dangling pointer in cpp \n";
	int * ptr = new int[10];
	int * ptr1 = ptr ;

	delete [] ptr;
	// now the ptr1 is dangling  
}