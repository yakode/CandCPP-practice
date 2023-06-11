// binary search tree of binary search tree
class SnapshotArray{
private:
    struct snapNode{
        int ver;
        int val;
        struct snapNode *left, *right;
    };
    struct Node{
        int id;
        struct snapNode *root;
        struct Node *left, *right;
    };
    
    struct Node *root;
    int n;
    int ver;

public:
    struct Node *init_tree(int start, int length){
        if(length == 0) return nullptr;
        int n = start + length / 2;
        int l = start, r = n + 1;
        struct Node* ptr = new struct Node;
        ptr->id = n;
        ptr->root = new struct snapNode();
        ptr->root->ver = 0;
        ptr->root->val = 0;
        ptr->root->left = nullptr;
        ptr->root->right = nullptr;
        ptr->left = init_tree(l, length / 2);
        ptr->right = init_tree(r, length - (length / 2 + 1));
        return ptr;
    }

    SnapshotArray(int length){
        ver = 0;
        this->root = init_tree(0, length);
    }
    
    void set(int index, int val){
        struct Node *ptr = this->root;
        while(ptr){
            if(ptr->id < index){
                ptr = ptr->right;
            }else if(ptr->id > index){
                ptr = ptr->left;
            }else{
                struct snapNode *tmp = ptr->root;
                while(tmp){
                    if(tmp->ver < this->ver){
                        if(tmp->right == nullptr){
                            tmp->right = new struct snapNode;
                            tmp = tmp->right;
                            break;
                        }else{
                            tmp = tmp->right;
                        }
                    }else if(tmp->ver > this->ver){
                        if(tmp->left == nullptr){
                            tmp->left = new struct snapNode;
                            tmp = tmp->left;
                            break;
                        }else{
                            tmp = tmp->left;
                        }
                    }else{
                        tmp->val = val;
                        return;
                    }
                }
                tmp->ver = this->ver;
                tmp->val = val;
                tmp->left = nullptr;
                tmp->right = nullptr;
                return;
            }
        }
    }
    
    int snap(){
        return ver++;
    }
    
    int get(int index, int snap_id){
        struct Node *ptr = root;
        while(ptr){
            if(index < ptr->id){
                ptr = ptr->left;
            }else if(index > ptr->id){
                ptr = ptr->right;
            }else{
                struct snapNode *tmp = ptr->root;
                while(tmp){
                    if(tmp->ver > snap_id){
                        if(tmp->left == nullptr) return 0;
                        tmp = tmp->left;
                    }else if(tmp->ver < snap_id){
                        if(tmp->right == nullptr || tmp->right->ver > snap_id) return tmp->val;
                        tmp = tmp->right;
                    }else{
                        return tmp->val;
                    }
                }
                break;
            }
        }

        return 0;
    }
};

// stl map
class SnapshotArray{
private:
    map<int, map<int, int>> snapMap;
    int version;
public:
    SnapshotArray(int length){
        for(int i = 0; i < length; ++i){
            snapMap[i][0] = 0;
        }
        version = 0;
    }

    void set(int index, int val){
        snapMap[index][version] = val;
    }

    int snap(){
        return version++;
    }

    int get(int index, int snap_id){
        auto it = snapMap[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};
