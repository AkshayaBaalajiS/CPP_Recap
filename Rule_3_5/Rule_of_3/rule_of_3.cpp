#include <iostream>
using namespace std;

void function(int & ref)
{
	cout<<"@void function(int & ref)\n";
}

void function(int && ref)
{
	cout<<"@void function(int && ref)\n";
}

class MyClass 
{
	int * data ;
	int size;
	public : 
		MyClass(int * d = nullptr, int size=0) : size(size), data(new int[size]) 
		{
			cout<<"My class constructor\n";
			for(int i=0;i<size;i++)
			{
				data[i] = d[i];
			}
		}	
		MyClass(const MyClass & ref) : size(ref.size), data(new int[size])
		{
			cout<<"My class copy constructor \n";

			for(int i=0;i<size;i++)
			{
				data[i] = ref.data[i];
			}
		}

		MyClass & operator= (const MyClass & ref)
		{
			cout<<"My class copy assignment operator \n";
			if(this!=&ref)
			{
				size = ref.size;
				delete data;
				data = new int[size];
				for(int i=0;i<size;i++)
				{
					data[i] = ref.data[i];
				}
			}
			return *this;
		}

		
		
		~MyClass()
		{
			cout<<"My class destructor\n";
			delete [] data;
		}
};

int main()
{
	cout<<"Move semantics in cpp \n";


	MyClass obj;
	MyClass obj1(obj);

	obj1 = obj;
}