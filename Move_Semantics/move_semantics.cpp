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

		MyClass(MyClass && ref) noexcept : size(ref.size), data(ref.data) 
		{
			cout<<"My class move constructor \n";

			ref.data = nullptr;
			ref.size = 0;
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

	int number = 24;

	function(std::move(number)); // move cast the lvalue to rvalue ref 

	function(number);

	MyClass obj;
	MyClass obj1(obj);
	MyClass obj2(std::move(obj1));

}