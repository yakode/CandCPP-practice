class Solution{
private:
    struct Node{
        int val;
        Node *left;
        Node *right;
        Node *parent;
        Node(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
        Node(int x, Node* left, Node* right, Node *parent) : val(x), left(left), right(right), parent(parent) {}
    };
    
public:
    Node* createGraph(TreeNode *root, TreeNode *target, Node *&newTarget){
        if(!root)
            return nullptr;
        
        Node *ptr = new Node(root->val);

        Node *leftnode = createGraph(root->left, target, newTarget);
        Node *rightnode = createGraph(root->right, target, newTarget);
        if(leftnode)
            leftnode->parent = ptr;
        if(rightnode)
            rightnode->parent = ptr;
        ptr->left = leftnode;
        ptr->right = rightnode;

        if(root->val == target->val)
            newTarget = ptr;

        return ptr;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k){
        vector<int> ans;
        queue<Node*> q;
        int dis = 0;
        int mark = 501;
        Node *newTarget = nullptr;
        Node *g = createGraph(root, target, newTarget);

        if(newTarget){
            newTarget->val += mark;
            q.push(newTarget);
        }
        
        while(!q.empty()){
            if(dis == k)
                break;
            
            int n = q.size();

            for(int i = 0; i < n; ++i){
                Node *ptr = q.front();
                q.pop();
                if(ptr->left && ptr->left->val <= 500){
                    ptr->left->val += mark;
                    q.push(ptr->left);
                }
                if(ptr->right && ptr->right->val <= 500){
                    ptr->right->val += mark;
                    q.push(ptr->right);
                }
                if(ptr->parent && ptr->parent->val <= 500){
                    ptr->parent->val += mark;
                    q.push(ptr->parent);
                }
                    
            }

            ++dis;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val - mark);
            q.pop();
        }

        return ans;
    }
};
