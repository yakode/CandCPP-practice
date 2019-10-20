#include <iostream>

class Node
{
   friend class Josephus;
   public:
        Node():next( NULL ){
        }
      	Node( const int &info ) //constructor
   	 :number( info ), next( NULL )
   	 {
   	 } //end ListNode constructor
   private:
      	Node *next;
        int number;
};//end class Node

class Josephus
{
    public:
         Josephus();
         ~Josephus();
         Josephus(const int &);
         int kill() ; // return the survival's position

    private:
        void generatecircularlinkedList(const int &); // generate circular linked-list
        void generateFib(const int &); // generate a Fibonacci sequence table
        int sequence[50]; // store Fibonacci number
        int noOfPeople;
        Node *head;
};

Josephus:: Josephus(){
	noOfPeople = 0;
	head = nullptr;
}

Josephus:: ~Josephus(){
	delete head;
}

Josephus::Josephus(const int &n){
	generatecircularlinkedList(n);
	noOfPeople = n;
}

int Josephus::kill(){
	int died = 1;
	int m;
	generateFib(noOfPeople);
	Node *ptr = head;
	Node *pre = head;
	while(pre->next != head) pre = pre->next;
	while(noOfPeople > 1){
		m = sequence[died++] % noOfPeople;
		if(m == 0) m = noOfPeople;
		for(int i = 0; i < m-1; i++) {ptr = ptr->next; pre = pre->next;}
		pre->next = ptr->next;
		Node* bye = ptr;
		if(ptr == head) head = head->next;
		ptr = ptr->next;
		delete bye;
		noOfPeople--;
	}
	return head->number;
}
void Josephus::generatecircularlinkedList(const int &n){
	head = new Node(1);
	Node *pre = head;
	for(int i = 2; i <= n; i++){
		Node* tmp = new Node(i);
		pre->next = tmp;
		pre = tmp;
	}
	pre->next = head;
}

void Josephus::generateFib(const int &n){
	sequence[1] = 1;
	sequence[2] = 1;
	for(int i = 3; i <= n; i++) sequence[i] = sequence[i-1] + sequence[i-2];
}

using namespace std;
int main(){
	int numofpeople;

	while(cin>>numofpeople){
		Josephus Jose(numofpeople);
		int survival = Jose.kill();
		cout<<survival<<endl;
    }
}

