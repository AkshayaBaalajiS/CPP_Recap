#include <iostream>
using namespace std;

void process(int & ref)
{
	cout<<"void process(int & ref)\n";
}

void process(int && ref)
{
	cout<<"void process(int && ref)\n";
}

template <typename T>
void forwarding(T && ref )
{
	process(std::forward<decltype(ref)>(ref));
}


int main()
{
	cout<<"This is the code to unedrstand the perfect forwarding in cpp \n";

	forwarding(234);
	
	int numbre = 345;
	forwarding(numbre);

}