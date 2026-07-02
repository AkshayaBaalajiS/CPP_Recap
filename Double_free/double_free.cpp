#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the double free in cpp \n";

	int * data  = new int[10];
	int * data1 = data ;

	// delete data;
	// delete data1;
	// here double delete happen this can be solved by the asiggning to nullptr 

	data = nullptr;

	delete data;
	delete data1;
	
}