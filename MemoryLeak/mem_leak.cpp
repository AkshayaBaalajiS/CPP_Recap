#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the memory leak in cpp \n";

	int * data = new int[10];

	int * data1 = new int[10]{12,23,34,54,56};

	data = data1;
	data1 = nullptr;

	cout<<"data = " << data[0] << " " << data[1] << endl;

	delete  [] data1;
	delete []  data;
	
}