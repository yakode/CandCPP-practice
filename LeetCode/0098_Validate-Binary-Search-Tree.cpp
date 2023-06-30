// my ugly code
class Solution{
public:
    bool traversal(TreeNode *root, long long maxi, long long mini){
        if(!root) return true;
        if(root->val >= maxi || root->val <= mini) return false;
        return traversal(root->left, min(maxi, (long long)root->val), mini) && traversal(root->right, maxi, max(mini, (long long)root->val));
    }

    bool isValidBST(TreeNode *root){
        return traversal(root, (long long)INT_MAX + 1, (long long)INT_MIN - 1);
    }
};
