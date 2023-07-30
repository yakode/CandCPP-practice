class Solution{
    int dfs(int i, int j, string &s, vector<vector<int>> &dp){
        if(i > j)
            return 0;
        if(dp[i][j] > 0)
            return dp[i][j];
        
        dp[i][j] = dfs(i + 1, j, s, dp) + 1;
        for(int k = i + 1; k <= j; ++k){
            if(s[i] == s[k]){
                dp[i][j] = min(dp[i][j], dfs(i + 1, k - 1, s, dp) + dfs(k, j, s, dp));
            }
        }

        return dp[i][j];
    }

public:
    int strangePrinter(string s){
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        return dfs(0, s.size() - 1, s, dp);
    }
};
