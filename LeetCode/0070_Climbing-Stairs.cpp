class Solution{
    int dfs(int n, vector<int> &dp){
        if(n < 0)
            return 0;
        if(n == 0)
            return 1;

        if(dp[n] > 0)
            return dp[n];

        return dp[n] = dfs(n - 1, dp) + dfs(n - 2, dp);
    }

public:
    int climbStairs(int n){
        vector<int> dp(n + 1, 0);
        
        return dfs(n, dp);
    }
};
