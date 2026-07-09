#include <iostream>
using namespace std;

template <typename T>
class A
{
	public:	
		T * ptr;
		int size ;
		A(int size=0, T * p=nullptr)
		{
			cout<<"@ A class constructor \n";
			if(p!=nullptr)
			{
				ptr = p ;
				p = nullptr;
			}
			else
			{
				if(size!=0)
				{
					ptr = new T[size];
				}
				else{
					cout<<"size is emoty and the p is nullptr\n";
				}
			}
		}
		A(const A & ref ) : size(ref.size)
		{
			cout<<"@ A class copy constructor \n";
			if(ref.ptr!=nullptr)
			{
				if(ref.size!=0)
				{
					ptr = new T[size];
				}
				
			
			}
			else
			{
				else{
					cout<<"size is emoty and the p is nullptr\n";
				}
			}
		}
		A(A && ref ) noexcept : size(ref.size)
		{
			cout<<"@ A class copy constructor \n";
			if(ref.ptr!=nullptr)
			{
				ptr = ref.ptr ;
				ref.ptr = nullptr;
			}
			else
			{
				if(ref.size!=0)
				{
					ptr = new T[size];
				}
				else{
					cout<<"size is emoty and the p is nullptr\n";
				}
			}
			ref.ptr = nullptr;
			ref.size = 0;
		}
		A& operator= (const A & ref ) 
		{
			cout<<"@ A class copy constructor \n";
			if(this!=&ref)
			{
				if(ref.ptr!=nullptr)
				{
					ptr = ref.ptr ;
					ref.ptr = nullptr;
				}
				else
				{
					size = ref.size;
					if(ref.size!=0)
					{
						ptr = new T[size];
					}
					else{
						cout<<"size is emoty and the p is nullptr\n";
					}
				}
			}
		}
		A& operator= (A && ref ) 
		{
			cout<<"@ A class move constructor \n";
			if(this!=&ref)
			{
				if(ref.ptr!=nullptr)
				{
					ptr = ref.ptr ;
					ref.ptr = nullptr;
				}
				else
				{
					size = ref.size;
					if(ref.size!=0)
					{
						ptr = new T[size];
					}
					else{
						cout<<"size is emoty and the p is nullptr\n";
					}
				}
			}
		}
};

int main()
{

}