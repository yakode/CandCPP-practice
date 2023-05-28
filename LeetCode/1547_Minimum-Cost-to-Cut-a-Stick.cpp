class Solution{
public:
    int dfs(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i + 1 == j) return 0;

        if(dp[i][j] > 0) return dp[i][j];

        int ret = INT_MAX;
        for(int k = i + 1; k < j; ++k){
            ret = min(ret, dfs(i, k, cuts, dp) + dfs(k, j, cuts, dp));
        }

        return dp[i][j] = ret + (cuts[j] - cuts[i]);
    }

    int minCost(int n, vector<int> &cuts){
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), 0));

        return dfs(0, cuts.size() - 1, cuts, dp);
    }
};
