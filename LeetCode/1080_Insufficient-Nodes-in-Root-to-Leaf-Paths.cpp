class Solution{
public:
    TreeNode* sufficientSubset(TreeNode *root, int limit){
        if(!root->left && !root->right){
            // leaf node
            if(limit - root->val > 0) return nullptr;
            return root;
        }

        TreeNode *left = nullptr, *right = nullptr;
        if(root->left) left = sufficientSubset(root->left, limit - root->val);
        if(root->right) right = sufficientSubset(root->right, limit - root->val);

        if(!left && !right) return nullptr;
        root->left = left;
        root->right = right;
        return root;
    }
};
