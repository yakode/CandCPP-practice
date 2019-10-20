#include <iostream>
using namespace std;

using Node = struct _Node{
	int data;
	struct _Node *prev;
	struct _Node *next;
};

int insert(Node* &head, Node* &tail){
	int ans = 0;
	if(head == nullptr){
		head = new Node;
		tail = head;
		cin >> head->data;
		head->prev = nullptr;
		head->next = nullptr;
	}else{
		tail->next = new Node;
		tail->next->prev = tail;
		tail = tail->next;
		tail->next = nullptr;
		cin >> tail->data;
		Node *ptr = tail;
		while(ptr->prev != nullptr){
			if(ptr->data < ptr->prev->data){
				int tmp = ptr->prev->data;
				ptr->prev->data = ptr->data;
				ptr->data = tmp;

				ans++;
				ptr = ptr->prev;	
			}else{
				break;
			}
		}
	}
	return ans;
}

int main(){
	int T, N;
	int ans = 0;
	Node *head, *tail;
	cin >> T;
	while(T--){
		cin >> N;
		head = nullptr;
		tail = nullptr;
		while(N--){
			ans += insert(head, tail);
		}
	}
	cout << ans << endl;
	return 0;
}
