class Solution{
public:
    int minDepth(TreeNode *root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int lpath = INT_MAX, rpath = INT_MAX;
        if(root->left) lpath = minDepth(root->left);
        if(root->right) rpath = minDepth(root->right);

        return min(lpath, rpath) + 1;
    }
};
