class Solution{
public:
    vector<int> dfs(TreeNode *root, int &ans){
        // isBST, sum, max, min
        if(!root) return {1, 0, INT_MIN, INT_MAX};

        vector<int> left = dfs(root->left, ans);
        vector<int> right = dfs(root->right, ans);

        if(left[0] == 0 || right[0] == 0 || root->val <= left[2] || root->val >= right[3]) return {0, 0, 0, 0};

        ans = max(ans, left[1] + right[1] + root->val);
        return {1, left[1] + right[1] + root->val, max(right[2], root->val), min(left[3], root->val)};
    }

    int maxSumBST(TreeNode *root){
        int ans = 0;

        dfs(root, ans);

        return max(ans, 0);
    }
};
