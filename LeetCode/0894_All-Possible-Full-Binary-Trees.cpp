vector<vector<TreeNode*>> dp(20, vector<TreeNode*>());
class Solution{
public:
    vector<TreeNode*> allPossibleFBT(int n){
        if(n % 2 == 0)
            return vector<TreeNode*>();
        if(n == 1)
            return vector<TreeNode*>(1, new TreeNode(0));
        if(dp[n].size() > 0)
            return dp[n];
        
        vector<TreeNode*> ans;
        for(int i = 1; i < n; i += 2){
            vector<TreeNode*> left = allPossibleFBT(i), right = allPossibleFBT(n - i - 1);
            for(auto l: left){
                for(auto r: right){
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return dp[n] = ans;
    }
};
