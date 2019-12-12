#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
	Node *left, *right;
	int key;
	int height;
}*root = nullptr;

Node* newNode(int x){
	Node *node = new Node;
	node->left = nullptr;
	node->right = nullptr;
	node->key = x;
	node->height = 1;
	return node;
}

int getHeight(Node* node){
	if(node == nullptr) return 0;
	return node->height;
}

int getBf(Node* node){
	if(node == nullptr) return 0;
	return getHeight(node->left) - getHeight(node->right);
}

Node* leftRotate(Node* node){
	Node* r = node->right;
	Node* rl = r->left;
	node->right = rl;
	r->left = node;
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
	return r;
}

Node* rightRotate(Node* node){
	Node* l = node->left;
	Node* lr = l->right;
	node->left = lr;
	l->right = node;
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	l->height = max(getHeight(l->left), getHeight(l->right)) + 1;
	return l;
}

Node* insert(Node *node, int x){
	if(node == nullptr)
		return newNode(x);

	if(x < node->key)
		node->left = insert(node->left, x);
	else if(x > node->key)
		node->right = insert(node->right, x);
	else
		return node;

	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	int bf = getBf(node);
	if(bf > 1){
		if(getBf(node->left) < 0){
			node->left = leftRotate(node->left);
		}
		return rightRotate(node);
	}
	if(bf < -1){
		if(getBf(node->right) > 0){
			node->right = rightRotate(node->right);
		}
		return leftRotate(node);
	}

	return node;
}

void levelOrder(Node* node){
	queue<Node*> q;
	q.push(node);
	while(!q.empty()){
		Node *tmp = q.front();
		q.pop();
		cout << tmp->key;
		if(tmp->left != nullptr) q.push(tmp->left);
		if(tmp->right != nullptr) q.push(tmp->right);
		if(!q.empty()) cout << ' ';
	}
	cout << '\n';
}

int main(){
	int T, N;
	cin >> T;
	while(T--){
		root = nullptr;
		cin >> N;
		for(int i = 0; i < N; ++i){
			int x;
			cin >> x;
			root = insert(root, x);
		}
		levelOrder(root);
	}
	return 0;
}
