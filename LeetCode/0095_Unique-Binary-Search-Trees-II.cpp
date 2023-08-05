class Solution{
    vector<TreeNode*> dfs(int i, int j, vector<vector<vector<TreeNode*>>> &dp){
        vector<TreeNode*> ret, left, right;
        
        if(i >= j)
            return vector<TreeNode*>(1, nullptr);

        if(dp[i][j].size() > 0)
            return dp[i][j];

        for(int k = i; k < j; ++k){
            left = dfs(i, k, dp);
            right = dfs(k + 1, j, dp);

            for(auto l: left){
                for(auto r: right){
                    TreeNode *tmp = new TreeNode(k + 1, l, r);
                    ret.push_back(tmp);
                }
            }
        }

        return dp[i][j] = ret;
    }

public:
    vector<TreeNode*> generateTrees(int n){
        vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));

        return dfs(0, n, dp);
    }
};
