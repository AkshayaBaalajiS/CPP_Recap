// Returning an object from a function efficiently.
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
		MyClass(int size=0, int * d = nullptr) : size(size), data(new int[size]) 
		{
			cout<<"My class constructor\n";
		if(d!=nullptr)
		{
			for(int i=0;i<size;i++)
				{
					data[i] = d[i];
				}
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
template <typename... T>
MyClass function1(T&&... args)
{
	return MyClass(std::forward<T>(args)...); // Return Value Optimization 
}

int main()
{
	cout<<"Move semantics in cpp \n";

	MyClass obj2 = function1(5); // cons 
	// return value semantics is object returned from a function and there wont be 2 cons called only one cons called 	

	cout<<"+++++++++++++++++++++++++++\n";
	MyClass obj3 = obj2; // copy constr 
	cout<<"+++++++++++++++++++++++++++\n";

	// which is similar to 
	cout<<"------------------------\n";
	MyClass obj4(12); // cons 
	MyClass obj5 = obj4; // copy cons 
	cout<<"------------------------\n";
}