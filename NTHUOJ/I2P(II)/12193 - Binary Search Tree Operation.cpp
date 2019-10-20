#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left;	
	Node *right;	
};

void insert(Node* &root, int x){
	if(root == nullptr){
		root = new Node;
		root->data = x;
		root->left = nullptr;
		root->right = nullptr;
	}else{
		Node *ptr = root;
		while(ptr != nullptr){
			if(x > ptr->data){
				if(ptr->right == nullptr){
					ptr->right = new Node;
					ptr = ptr->right;
					ptr->data = x;
					ptr->left = nullptr;
					ptr->right = nullptr;
					return;
				}
				ptr = ptr->right;
			}else if(x < ptr->data){
				if(ptr->left == nullptr){
					ptr->left = new Node;
					ptr = ptr->left;
					ptr->data = x;
					ptr->left = nullptr;
					ptr->right = nullptr;
					return;
				}
				ptr = ptr->left;
			}else break;
		}
	}
}

int GetMax(Node *root){
	if(root == nullptr) return 0;
	return max(GetMax(root->left), GetMax(root->right))+1;
}

int Sum(Node *root, int h, int goal){
	if(root == nullptr || h > goal) return 0;
	if(h == goal) return root->data;
	return Sum(root->left, h+1, goal) + Sum(root->right, h+1, goal);
}

int count(Node *root, int h, int goal){	
	if(root == nullptr || h > goal) return 0;
	if(h == goal) return 1;
	return count(root->left, h+1, goal) + count(root->right, h+1, goal);
}

void P(Node* root){
	if(root == nullptr) return;
	P(root->left);
	cout << root->data << ' ';
	P(root->right);
}

int main(){
	int N, M, x;
	Node *root = nullptr;
	cin >> N;
	while(N--){
		cin >> x;
		insert(root, x);
	}
	char cmd[10];
	cin >> M;
	int height = GetMax(root);
	while(M--){
		cin >> cmd;
		if(cmd[0] == 'P'){
			if(root == nullptr) cout << "NULL\n";
			else{
				P(root);
				cout << '\n';
			}
		}else if(cmd[0] == 'G'){
			cout << height << endl;
		}else if(cmd[0] == 'S'){
			cin >> x;
			if(x > height || x == 0) cout << "0\n";
			else{
				cout << Sum(root, 1, x) << '\n';
			}
		}else if(cmd[0] == 'A'){
			cin >> x;
			if(x > height || x == 0) cout << "0\n";
			else{
				printf("%.3lf\n", (double)Sum(root, 1, x)/count(root, 1, x));
			}
		}
	}
	return 0;
}
