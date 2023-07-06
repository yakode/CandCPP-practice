class Solution{
public:
    TreeNode *ans;
    
    int traversal(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root) return 0;

        int ret = 0;

        if(root == p)
            ret += 1;
        if(root == q)
            ret += 2;
        ret = ret + traversal(root->left, p, q) + traversal(root->right, p, q);
        if(ret == 3 && ans == nullptr){
            ans = root;
        }

        return ret;
    }

    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        ans = nullptr;

        traversal(root, p, q);

        return ans;
    }
};
