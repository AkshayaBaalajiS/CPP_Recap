#include <iostream>
using namespace std;

class MyClass
{
	public:
		int size ;
		int * data ;
		MyClass(int size = 0 , int *da = nullptr ) : size(size), data(da)
		{
			cout<<"@  MyClass constructor \n";
			if(da!=nullptr)
			{
				for(int i=0;i<size;i++)
				{
					data[i] = da[i];
				}
			}
		}	

		MyClass(const MyClass & ref) : size(ref.size), data(new int[size])
		{
			cout<<"@  MyClass constructor \n";
			if(ref.data!=nullptr)
			{
				for(int i=0;i<size;i++)
				{
					data[i] = ref.data[i];
				}
			}

		}

		MyClass(MyClass && ref) noexcept : size(ref.size)
		{
			cout<<"@  MyClass constructor \n";
			data = ref.data;
			ref.data =  nullptr;
		}

		MyClass & operator=(MyClass & ref)
		{
			if(this!=&ref)
			{
				size = ref.size ;
				if(data!=nullptr)
				{
					delete [] data;
				}
				data =  new int [size];
				for(int i=0;i<size;i++)
				{
					data[i] = ref.data[i];
				}
			}
			return *this;
		}

		MyClass & operator=(MyClass && ref) noexcept
		{
			if(this!=&ref)
			{
				size = ref.size ;
				if(data!=nullptr)
				{
					delete [] data;
				}
				data = ref.data;
			}
			return *this;
		}


		~MyClass()
		{
			cout<<"@  MyClass destructor \n";
		}	
		
};

void func(MyClass & ref )
{
	cout<<"This is the l value reference function \n";
}

void func(MyClass && ref )
{
	cout<<"This is the r value reference function \n";
}


template <typename... T>
void function1(T&&...  ref ) // variadic templte 
{
	return func(std::forward<T>(ref)...);
}

int main()
{
	cout<<"This is the program to understand the variadic template \n";
	MyClass obj;
	function1(obj);
	function1(std::move(obj));

}

