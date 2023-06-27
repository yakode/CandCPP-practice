class Solution{
public:
    int ans = 0;
    void dfs(TreeNode *root, int num){
        num = num * 10 + root->val;
        if(!root->left && !root->right){
            ans += num;
            return;
        }

        if(root->left) dfs(root->left, num);
        if(root->right) dfs(root->right, num);
    }
    int sumNumbers(TreeNode *root){
        dfs(root, 0);
        return ans;
    }
};
