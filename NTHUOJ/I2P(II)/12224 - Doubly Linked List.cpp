#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ListNode{
private:
    int data;
    ListNode *next;
    ListNode *prev;
public:
    ListNode():data(0),next(nullptr), prev(nullptr){};
    ListNode(int a):data(a),next(nullptr), prev(nullptr){};

    friend class List;
};

class List {
private:
    ListNode* head;  // head of the doubly linked list
    ListNode* tail;  // tail of the doubly linked list
    ListNode* middle; // middle of the list
    int       cnt;   // total count of the elements in the list
    int       pos;   // the position of middle

    void reset(){
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        cnt = 0;
        pos = 0;
    }

    void clean(){
        ListNode* temp;
        while(head!=nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    // constructor and destructor
    List(){
        reset();
    }

    ~List(){
        clean();
    }

    void InsertHead(int data);
    int  RemoveHead();
    void InsertTail(int data);
    int  RemoveTail();
    void Swap();
    int  getSize();
    int  getMiddle();

};

void List::InsertHead(int data){
	cnt++;
	if(head == nullptr){
		head = new ListNode(data);
		tail = head;
		middle = head;
	}else{
		head->prev = new ListNode(data);
		head->prev->next = head;
		head = head->prev;
		if(cnt%2 == 1) middle = middle->prev;
	}
}
int List::RemoveHead(){
	if(head == nullptr) throw out_of_range("123");
	else{
		cnt--;
		ListNode *bye = head;
		int ans = head->data;
		head = head->next;
		delete bye;
		if(cnt != 0){
			head->prev = nullptr;
			if(cnt%2 == 0)
				middle = middle->next;
		}else{
			tail = nullptr;
			middle = nullptr;
		}
		return ans;
	}
}
void List::InsertTail(int data){
	cnt++;
	if(head == nullptr){
		head = tail = middle = new ListNode(data);
	}else{
		ListNode* tmp = new ListNode(data);
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
		if(cnt%2 == 0) middle = middle->next;
	}
}
int List::RemoveTail(){
	if(cnt == 0) throw out_of_range("123");
	else{
		cnt--;
		int ans = tail->data;
		ListNode *bye = tail;
		tail = tail->prev;
		delete bye;
		if(cnt != 0){
			tail->next = nullptr;
			if(cnt%2 == 1)
				middle = middle->prev;
		}else{
			head = nullptr;
			middle = nullptr;
		}
		return ans;
	}
}
void List::Swap(){
	if(head != nullptr){
		ListNode *tmp;
		if(cnt%2 == 0) tmp = head;
		else tmp = tail;
		tail->next = head;
		head->prev = tail;
		tail = middle->prev;
		tail->next = nullptr;
		head = middle;
		head->prev = nullptr;
		middle = tmp;
	}
}

int main(){
    List L;
    string cmd;
    int data, cnt=0, pos = 0;

    while(cin >> cmd){
        if(cmd=="IH"){ // insert an integer to the head
            cin >> data;
            L.InsertHead(data);
        } else if (cmd=="IT"){ // insert an integer to the end
            cin >> data;
            L.InsertTail( data);
        } else if (cmd=="RH"){   // print and remove a node from head
            try {
                cout<< L.RemoveHead() <<endl;
            } catch (const out_of_range &e){
                cout << endl;
            }
        } else if (cmd=="RT") {// print and remove a node from tail
            try {
                cout << L.RemoveTail()<<endl;
            } catch (const out_of_range &e){
                cout << endl;
            }
        } else if (cmd=="S"){
            L.Swap();
        }
		//L.show_tail();
    }
}
