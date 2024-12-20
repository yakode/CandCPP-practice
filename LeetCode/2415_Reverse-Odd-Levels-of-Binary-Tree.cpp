class Solution{
    void dfs(TreeNode *left, TreeNode *right, bool odd){
        if(!left)
            return;
        if(odd)
            swap(left->val, right->val);
        dfs(left->left, right->right, !odd);
        dfs(left->right, right->left, !odd);
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode *root){
        dfs(root->left, root->right, 1);
        return root;
    }
};
