class Solution{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(!p || !q) return p == q;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root){
        return isSameTree(root->left, root->right);
    }
};
