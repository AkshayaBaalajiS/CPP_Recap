#include <iostream>
#include <memory>

using namespace std;


template <typename T>
class MyClass
{
	T * data ; 
	int size;
	public:
		MyClass(int size = 0, T * da = nullptr) : size(size), data(da)
		{
			cout<<"@ MyClass constructor \n";
			if(size>0)
			{
				data = new T[size];
			}
		}

		// operator overloading 
		T & operator[](const int & index)
		{
			if(index< size)
			{
				return data[index];
			}
		}
		
		// MyClass & operator[](const int & val)
		// {
		// 	if(index< size)
		// 	{
		// 		return data[index];
		// 	}
		// }


		void display()
		{
			for(int i=0;i<size;i++)
			{
				cout<<data[i]<< "  " ; 
			}
			cout<<endl;
		}

		MyClass(const MyClass & ref) : size(ref.size), data(new T[size])
		{
			cout<<"@ MyClass copy constructor \n";
			for(int i=0;i<size;i++)
			{
				data[i] = ref.data[i];
			}
		}
		
		MyClass(MyClass && ref) : size(ref.size), data(ref.data)
		{
			ref.size= 0;
			ref.data= nullptr;
		}

		MyClass & operator= (const MyClass & ref)
		{
			cout<<"Copy assignement operator\n";
			if(this!=&ref)
			{
				size =  ref.size;
				delete [] data;
				data = new T[size];
				for(int i=0;i<size;i++)
				{
					data[i] = ref.data[i];
				}	
			}
			return *this;
		}

		MyClass & operator= (MyClass && ref)
		{
			cout<<"Move assignement operator\n";
			if(this!=&ref)
			{
				size =  ref.size;
				delete [] data;
				data = ref.data;
				ref.size = 0;
				ref.data = nullptr;	
			}

			return *this;
		}

		~MyClass()
		{
			cout<<"MyClass destructor\n";
			delete [] data;
		}

};

int main()
{
	cout<<"This is the program to understand the smart pointer \n";
	shared_ptr<MyClass<int>> shared1 = make_shared<MyClass<int>>(12);
	(*shared1)[0] = 234;
	(*shared1)[1] = 345;
	(*shared1)[2] = 456;
	shared1->display();

	//1. use_count 
	cout<<"Reference count for shared1  = " << shared1.use_count() <<endl;

	shared_ptr<MyClass<int>> shared2 = shared1;
	(*shared2)[4] = 567;
	shared2->display();
	shared1->display(); // as shared it affect the parent also
	cout<<"Reference count for shared1  = " << shared1.use_count() <<endl;
	cout<<"Reference count  shared2  = " << shared2.use_count() <<endl;

	shared_ptr<MyClass<int>> shared3 = shared1;
	(*shared3)[5] = 787;
	shared3->display();
	shared1->display(); // as shared it affect the parent also
	cout<<"Reference count for shared1  = " << shared1.use_count() <<endl;
	cout<<"Reference count  shared3  = " << shared3.use_count() <<endl;

	// 2 . reset 
	shared1.reset();
	cout<<"Reference count for shared1  = " << shared1.use_count() <<endl;
	cout<<"Reference count  shared3  = " << shared3.use_count() <<endl;
	cout<<"Reference count  shared2  = " << shared2.use_count() <<endl;
	// only the reset done on the shared 1 and now the shared2 is having the use_count as 2 and the shared3 use_count is 2 

	// 3. custom deleter is not there for the unique ptr 
	auto lambda = [](MyClass<int>* args)
	{
		cout<<"Custom deleter for shared\n";
		delete args;
	};

	shared_ptr<MyClass<int>> shared4 (new MyClass<int>(33), lambda);

	// get 
	MyClass<int> * mycls = shared4.get();
	(*mycls)[4] = 678;
	mycls->display();

	(*shared4)[3] = 456;
	shared4->display();

	// testing the move cons for the shared ptr 
	shared_ptr<MyClass<int>> shared5 =  std::move(shared4);

	// no release in shared ptr  
	// MyClass<int> * mycls1 = shared4.release();
	// (*mycls1)[4] = 678;
	// mycls1->display();

	// as released this cant be done
	// (*shared4)[3] = 456;
	// shared4->display();


}