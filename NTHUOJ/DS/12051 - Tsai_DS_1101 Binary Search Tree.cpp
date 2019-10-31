#include <iostream>
#include <string>
using namespace std;

class Node{
	private:
		int data;
		Node *leftChild;
		Node *rightChild;
	public:
		Node(int x):data(x), leftChild(nullptr), rightChild(nullptr){}
		~Node(){}
		Node* get_lc(){return leftChild;}
		Node* get_rc(){return rightChild;}
		void set_lc(Node *ptr){leftChild = ptr;}
		void set_rc(Node *ptr){rightChild = ptr;}
		int get_data(){return data;}
		void set_data(int x){data = x;}
};

void insert(Node** root, int x){
	if(*root == nullptr){
		*root = new Node(x);
	}else{
		Node *current = *root;
		while(current != nullptr){
			if(x < current->get_data()){
				if(current->get_lc() == nullptr){
					current->set_lc(new Node(x));
					return;
				}else{
					current = current->get_lc();
				}
			}else if(x > current->get_data()){
				if(current->get_rc() == nullptr){
					current->set_rc(new Node(x));
					return;
				}else{
					current = current->get_rc();
				}
			}else{
				return;
			}
		}
	}
}

void print(Node* root){
	if(root == nullptr) return;
	print(root->get_lc());
	cout << root->get_data() << ' ';
	print(root->get_rc());
}

void delet(Node** root, int x){
	Node *ptr = *root;
	Node *pre = nullptr;
	while(ptr != nullptr){
		if(ptr->get_data() == x) break;
		else if(x < ptr->get_data()){
			pre = ptr;
			ptr = ptr->get_lc();
		}else if(x > ptr->get_data()){
			pre = ptr;
			ptr = ptr->get_rc();
		}
	}
	if(ptr == nullptr) return;

	int numLeaf = 0;
	if(ptr->get_lc() != nullptr) numLeaf++;
	if(ptr->get_rc() != nullptr) numLeaf++;

	if(numLeaf == 0){
		if(pre == nullptr) *root = nullptr;
		else if(pre->get_lc() == ptr) pre->set_lc(nullptr);
		else if(pre->get_rc() == ptr) pre->set_rc(nullptr);
	}else if(numLeaf == 1){
		Node *tmp;
		if(ptr->get_lc()!= nullptr) tmp = ptr->get_lc();
		if(ptr->get_rc()!= nullptr) tmp = ptr->get_rc();
		if(pre == nullptr) *root = tmp;
		else if(pre->get_lc() == ptr) pre->set_lc(tmp);
		else if(pre->get_rc() == ptr) pre->set_rc(tmp);
	}else if(numLeaf == 2){
		Node *tmp = ptr->get_lc();
		while(tmp->get_rc() != nullptr) tmp = tmp->get_rc();
		int y = tmp->get_data();
		delet(root, y);
		ptr->set_data(y);
	}
}

int main(){
	int N;
	cin >> N;
	string cmd;
	int x;
	Node *root = nullptr;
	while(N--){
		cin >> cmd;
		if(cmd == "Insert"){
			cin >> x;
			insert(&root, x);
		}else if(cmd == "Delete"){
			cin >> x;
			delet(&root, x);
		}else if(cmd == "Print"){
			print(root);
			cout << '\n';
		}	
	}
	return 0;
}
