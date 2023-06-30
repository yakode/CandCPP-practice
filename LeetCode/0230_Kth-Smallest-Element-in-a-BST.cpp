class Solution{
public:
    int kthSmallest(TreeNode *root, int &k){
        if(!root) return 0;
        if(k == 0) return 0;

        int left, right;

        left = kthSmallest(root->left, k);
        k -= 1;
        if(k == 0) return root->val;
        right = kthSmallest(root->right, k);

        return left + right;
    }
};
