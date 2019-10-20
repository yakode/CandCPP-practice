#pragma once

struct Node
{
    int value;
    Node *right;
    Node *left;

    Node(int v)
        :value(v)
        ,right(nullptr)
        ,left(nullptr) {}
    
    ~Node()
    {
        delete right;
        delete left;
    }
};

struct Content{
	vector<int> arr;
};

class Iterator
{
public:
    void *data;

    Iterator(Node *);
    Iterator(const Iterator &other);
    ~Iterator();
    int operator*() const;
    bool operator!=(const Iterator &) const;
    void operator++(int);
};

void get_arr(void *data, Node *root){
	//pre order
	if(root == nullptr) return;
	data->arr.push_back(root);
	get_arr(data, root->left);
	get_arr(data, root->right);
}

Iterator::Iterator(Node *root){
	data = new Content;
	get_arr(data, root);
}
Iterator::Iterator(const Iterator &other){
	data = other.data;
}
Iterator::~Iterator();
Iterator::int operator*() const;
Iterator::bool operator!=(const Iterator &other) const{
	if(this.data->arr.size() != other.data->arr.size()) return true;
	int sz = this.data->arr.size();
	for(int i = 0; i < sz; ++i){
		if(this.data->arr[i] != other.data->arr[i]) return true;
	}
	return false;
}
Iterator::void operator++(int){
	
}


class BST
{
public:
    BST():m_root(nullptr){}
    ~BST(){delete m_root;}

    void push_back(int val)
    {
        Node **pos = &m_root;

        while( *pos )
        {
            if( (*pos)->value < val ) pos = &(*pos)->right;
            else pos = &(*pos)->left;
        }
        
        *pos = new Node(val);
    }
    
    Iterator begin()
    {
        Iterator it(m_root);
        return it;
    }

    Iterator end()
    {
        Iterator end(nullptr);
        return end;
    }

private:
    Node *m_root;
};

