class Solution{
public:
    int dfs(TreeNode *root, int mini, int maxi){
        if(!root) return 0;
        
        int diff = max(abs(root->val - mini), abs(root->val - maxi));
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        return max(diff, max(dfs(root->left, mini, maxi), dfs(root->right, mini, maxi)));
    }
    int maxAncestorDiff(TreeNode *root){
        return dfs(root, root->val, root->val);
    }
};
