#include<iostream>
using namespace std;

class LinkedList;

class Node 
{
	int data ;
	Node * next ;
	public :
		Node(int number = 0, Node * nextt=nullptr ) : data(number), next(nextt)
		{
			cout<<"@Node class constructor\n";
		}

		~Node()
		{
			cout<<"@Node class Destructor\n";
		}
		friend LinkedList;

};

class LinkedList
{
	Node * node;
	int numberOfNode; 
	public :
		LinkedList() : numberOfNode(0), node(nullptr)
		{
			cout<<"@ LinkedList class constructor\n";
		}

		LinkedList(const LinkedList & ref) : numberOfNode(ref.numberOfNode), node(new Node[numberOfNode])
		{
			cout<<"@LinkedList class copy constructor\n";
			for(int i=0;i<numberOfNode;i++)
			{
				node[i] = ref.node[i];
			}
		}
		
		LinkedList & operator=(const LinkedList & ref)
		{
			cout<<"@LinkedList class copy assignment operator\n";
			if(this != &ref)
			{
				numberOfNode = ref.numberOfNode;
				delete [] node ; 
				node = new Node[numberOfNode];
				for(int i=0;i<numberOfNode;i++)
				{
					node[i] = ref.node[i];
				}
			}
			return *this;

		}

		void insertAtHead(const int & number)
		{
			cout<<"Insertion at head \n";
			if(node==nullptr)
			{
				Node * nn =  new Node(number, nullptr);
				node = nn;
			}
			else
			{
				Node * nn = new Node(number);
				nn->next = node;
				node = nn;	
			}
			numberOfNode++;
		}


		void insertAtTail(const int & number)
		{
			cout<<"Insertion at head \n";
			if(node==nullptr)
			{
				Node * nn =  new Node(number, nullptr);
				node = nn;
			}
			else
			{
				Node * nn = new Node(number);
				Node * traverse = node;
				for(int i=0; traverse->next!=nullptr;i++)
				{
					traverse= traverse->next;
				}
				traverse->next = nn;	
			}
			numberOfNode++;
		}

		LinkedList & operator=(LinkedList && ref)  
		{
			cout<<"@LinkedList class move assignment operator\n";
			if(this != &ref)
			{
				delete [] node;
				numberOfNode = ref.numberOfNode;
				node = ref.node;
				ref.node = nullptr;
				ref.numberOfNode = 0 ;
			}
			return *this;
		}


		void display()
		{
			Node * nn = node;
			for(int i=0;i<numberOfNode && nn!=nullptr;i++)
			{
				cout<< nn->data << "  " ; 
				nn=nn->next;
			} 
			cout<<endl;
		}

		LinkedList(LinkedList && ref) : numberOfNode(ref.numberOfNode), node(ref.node)
		{
			cout<<"@LinkedList class move constructor\n";
			ref.numberOfNode = 0 ;
			ref.node = nullptr ;
		}


		~LinkedList()
		{
			cout<<"@ LinkedList class destructor\n";
			while(node!=nullptr)
			{
				Node * dn = node->next;
				delete node ;
				node= dn;
			}
		}
		
};

int main()
{
	cout<<"This is the program to understand the Linked List in cpp \n";
	LinkedList * ll = new LinkedList();

	// insert at head 
	ll->insertAtHead(12);
	ll->insertAtHead(23);
	ll->display();
	ll->insertAtHead(34);
	ll->insertAtHead(45);
	ll->display();
	ll->insertAtHead(45);
	ll->insertAtHead(56);
	ll->display();
	ll->insertAtTail(67);
	ll->insertAtTail(78);
	ll->display();




	delete  ll; 

}
