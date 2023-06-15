class Solution{
public:
    int ans = INT_MAX;
    int prev = -1;

    void traverse(TreeNode *node){
        if(node == nullptr) return;

        traverse(node->left);
        if(prev > -1) ans = min(ans, node->val - prev);
        prev = node->val;
        traverse(node->right);
    }

    int getMinimumDifference(TreeNode *root){
        traverse(root);

        return ans;
    }
};
