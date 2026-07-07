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

unique_ptr<MyClass<int>> function1(unique_ptr<MyClass<int>> up) 
{
	(*up)[4]=123;
	up->display();
	
	return up;
	// return std::move(up);
}

int main()
{
	cout<<"This is the program to understand the unique ptr in cpp \n";

	MyClass<int> * ptr = new MyClass<int>(12);
	(*ptr)[0] = 12;
	(*ptr)[1] = 23;
	(*ptr)[3] = 34;
	ptr->display();
	

	unique_ptr<MyClass<int>> up = make_unique<MyClass<int>>(23);
	(*up)[0] =234;
	(*up)[1] =345;
	(*up)[2] =456;
	up->display();

	unique_ptr<MyClass<int>> up1(std::move(up));
	up1->display();
	// now the up has no data due to move 
	// up->display();

	unique_ptr<MyClass<int>> up2  = std::move(up1);
	up2->display();	

	// the below raw pointer should not be passed to uniqe pointer 
	unique_ptr<MyClass<int>> up3(ptr); // here delte will happen and if the raw pointer deleted there is a double delete 
	ptr = nullptr; // this can be done to avoid doublt delete 


	up3 = function1(std::move(up3));
	(*up3)[5] = 234;
	up3->display();



	// 1. release
	MyClass<int> *  mycls = up3.release();
	(*mycls)[6]=678;
	mycls->display();
	// the below cant be done 
	// up3->display(); 
	
	// 2. reset can be for deleting the current and renewing with some other object 
	up3.reset();
	up3.reset(mycls); // renew qith mycls 
	(*up3)[8] = 234;
	up3->display();

	// 3 .get 
	MyClass<int> * mycls1 = up3.get();
	(*mycls1)[9]=34;
	mycls1->display();
	// still the unique pointer own the pointer and should not deelte the pointer which we get 
	(*up3)[10] = 234;
	up3->display();


	// 4. Custom deleter 
	auto lambda = [](MyClass<int> * ptr)
	{
		cout<<"Lambda function for deleting \n";
		delete ptr;
	};
	//unique_ptr<MyClass<int>, decltype(lambda)> up4  = make_unique<MyClass<int>>(123);
 	// the above cant be done cause make unique return a unique ptr with def deleter 

 	unique_ptr<MyClass<int>, decltype(lambda)> up4 (new MyClass<int>(123), lambda);
 
	delete  ptr;
}