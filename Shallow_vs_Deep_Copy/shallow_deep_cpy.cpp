#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the shallow and deep copy in cpp \n";

	int * data = new int[10];// {12,23,34,45,56,67,78,89};
	// int * arra  = {1,2,3,4,5,6,7,8,9};
	int * arra  = new int[10] {1,2,3,4,5,6,7,8,9};
	// shallow copy 
	int * data1 = data ; // this is shallow copy 

	cout<<"data = "  << data <<endl;
	cout<<"data1 = "  << data1 <<endl;

	// deep copy 
	int * data2 = new int [10];
	for(int i=0;i<10;i++)
	{
		data2[i]  = data[i];
	}
	cout<<"data2 = "  << data2 <<endl;


	delete [] data;
	// delete [] data1; // error due to shallow copy 
	delete [] data2;
	
}