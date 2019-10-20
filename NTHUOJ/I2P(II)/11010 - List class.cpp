#include <iostream>
#include <string>

class ListNode
{
    friend class OWList; //make OWList a friend
    friend class TWList; //make TWList a friend

public:
    ListNode( const int &info ) //constructor
    : data( info ), nextPtr( NULL )
    {
    } //end ListNode constructor

private:
    int data; //data
    ListNode *nextPtr; // next node in list
}; //end class ListNode


class OWList
{
public:
    //default constructor
    OWList();
    //destructor
    ~OWList();
    //insert node at front of list
    void insertAtFront( const int &value );
    //remove node from front of list
    void removeFromFront();
    //is List empty?
    bool isEmpty() const;
    //display contents of List
    void print() const;

protected:
    ListNode *firstPtr; //pointer to first node
    ListNode *lastPtr;  //pointer to last node

}; // end class List

OWList::OWList(): firstPtr(nullptr), lastPtr(nullptr){}
OWList::~OWList(){
	ListNode *ptr = firstPtr;
	while(ptr != nullptr){
		ListNode *bye = ptr;
		ptr = ptr->nextPtr;
		delete bye;
	}
}

void OWList::insertAtFront(const int &value){
	if(isEmpty() == true){
		firstPtr = new ListNode(value);
		lastPtr = firstPtr;
	}else{
		ListNode* ptr = new ListNode(value);
		ptr->nextPtr = firstPtr;
		firstPtr = ptr;
	}
}
void OWList::removeFromFront(){
	if(isEmpty() == false){
		if(firstPtr == lastPtr){
			delete firstPtr;
			firstPtr = nullptr;
			lastPtr = nullptr;
		}else{
			ListNode *ptr = firstPtr;
			firstPtr = firstPtr->nextPtr;
			delete ptr;
		}
	}
}
bool OWList::isEmpty()const{
	if(firstPtr == nullptr) return true;
	else return false;
}
void OWList::print()const{
	if(isEmpty() == false){
		ListNode *ptr = firstPtr;
		while(ptr != lastPtr){
			std::cout << ptr->data << " ";
			ptr = ptr->nextPtr;
		}
		std::cout << lastPtr->data;
	}
}

class TWList:public OWList
{
public:
    //default constructor
    TWList()
    :OWList()
    {
        /*It will still work correctly if you omit the constructor call of the base
          class in the above member initializer list. The compiler will invoke this
          default constructor of OWList implicitly.*/
    }
    //destructor
    ~TWList()
    {
        /*You don't need to delete the list again because the compiler
          will invoke the destructor of the base class OWList to do this.*/
    }
    //insert node at back of list
    void insertAtBack( const int &value );
    //delete node from back of list
    void removeFromBack();

};
void TWList::insertAtBack( const int &value ){
	if(isEmpty() == true){
		lastPtr = new ListNode(value);
		firstPtr = lastPtr;
	}else{
		lastPtr->nextPtr = new ListNode(value);
		lastPtr = lastPtr->nextPtr;
	}
}

void TWList::removeFromBack(){
	if(isEmpty() == false){
		if(firstPtr == lastPtr){
			delete lastPtr;
			firstPtr = nullptr;
			lastPtr = nullptr;
		}else{
			ListNode *ptr = firstPtr;
			while(ptr->nextPtr != lastPtr) ptr = ptr->nextPtr;
			lastPtr = ptr;
			delete ptr->nextPtr;
			ptr->nextPtr = nullptr;
		}
	}
}

using namespace std;
int main()
{
    TWList integerList;
    int command;
    int value; // store node value

    while (cin >> command)
    {
        switch(command)
        {
        case 1: // insert at beginning
            cin >> value;
            integerList.insertAtFront(value);
            break;
        case 2: // insert at end
            cin >> value;
            integerList.insertAtBack(value);
            break;
        case 3: // remove from beginning
            integerList.removeFromFront();
            break;
        case 4: // remove from end
            integerList.removeFromBack();
            break;
        }
    }
    integerList.print();
    cout<<endl;
}

