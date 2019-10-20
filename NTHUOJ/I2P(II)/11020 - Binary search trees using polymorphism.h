#include <iostream>
#include <math.h>
using namespace std;

class BST{
public:
    BST():Height(0){}
    virtual ~BST() {}
    virtual void insert(const int &) = 0;
    virtual bool search(const int &) const = 0;
    virtual void print() const = 0;
    int height() const { return Height; }// An empty tree has height of 0. A tree with only root node has height of 1.

protected:
    int Height;
};

class Array_BST : public BST{
public:
    Array_BST();
    virtual ~Array_BST() {}
    virtual void insert(const int &) override; //root node is stored at index 1.
    virtual bool search(const int &) const override;
    virtual void print() const override{
        int k = pow(2, height());
        for (int i = 1; i <= k-1; i++) {
            if (array[i] != 0)
                cout << array[i] << " ";
        }
    }

private:
    int array[1025];
};

Array_BST::Array_BST():BST(), array{0}{}
void Array_BST::insert(const int &data){
	if(array[1] == 0){
		array[1] = data;
		Height = 1;
	}else{
		int pos = 1;
		int h = 1;
		while(1){
			if(data > array[pos]){
				pos = 2*pos + 1;
				h++;
				if(array[pos] == 0){
					array[pos] = data;
					if(h > Height) Height = h;
					break;
				}
			}else if(data < array[pos]){
				pos *= 2;
				h++;
				if(array[pos] == 0){
					array[pos] = data;
					if(h > Height) Height = h;
					break;
				}
			}else break;
		}
	}
}
bool Array_BST::search(const int &data) const{
	int pos = 1;
	while(1){
		if(array[pos] == 0) return false;

		if(data < array[pos]) pos = pos *2;
		else if(data > array[pos]) pos = pos*2 +1;
		else return true;
	}	
}

class ListNode{
    friend class List_BST; //make List_BST a friend

public:
    ListNode(const int &info):key( info ),left( NULL ),right( NULL ) //constructor
    {
    }//end ListNode constructor

private:
    int key;
    ListNode *left;
    ListNode *right;
};//end class ListNode

class List_BST : public BST{
public:
    List_BST();
    virtual ~List_BST()
    {
        deleteTree(root);
    }
    virtual void insert(const int &) override;
    virtual bool search(const int &) const override;
    virtual void print() const override{
        int i;
        for(i = 1; i <= Height; i++){
            printGivenLevel(root, i);
        }
    }

private:
    ListNode *root;
    // private member functions
    ListNode* createLeaf(int key) const; //new a ListNode and return its address
    /* clean a tree.*/
    void deleteTree(ListNode *root);

    void printGivenLevel(ListNode* Ptr, int level) const {
        if (Ptr == NULL)
            return;
        if (level == 1)
            cout << Ptr->key << " ";
        else if (level > 1)
        {
            printGivenLevel(Ptr->left, level-1);
            printGivenLevel(Ptr->right, level-1);
        }
    }
};

List_BST::List_BST(): BST(), root(NULL){}
void List_BST::insert(const int &data){
	if(root == NULL){
		root = createLeaf(data);
		Height = 1;
	}else{
		ListNode *ptr = root;
		int h = 1;
		while(1){
			if(data < ptr->key){
				h++;
				if(ptr->left == NULL){
					ptr->left = createLeaf(data);
					if(h > Height) Height = h;
					break;
				}else{
					ptr = ptr->left;
				}
			}else if(data > ptr->key){
				h++;
				if(ptr->right == NULL){
					ptr->right = createLeaf(data);
					if(h > Height) Height = h;
					break;
				}else{
					ptr = ptr->right;
				}
			}else break;
		}
	}
}
bool List_BST::search(const int &data) const{
	ListNode *ptr = root;
	while(ptr != NULL){
		if(ptr->key == data) return true;
		else if(data > ptr->key) ptr = ptr->right;
		else if(data < ptr->key) ptr = ptr->left;
	}
	return false;
}
ListNode* List_BST::createLeaf(int key) const{
	ListNode *ptr = new ListNode(key);
	return ptr;
}
void List_BST::deleteTree(ListNode *root){
	if(root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}
