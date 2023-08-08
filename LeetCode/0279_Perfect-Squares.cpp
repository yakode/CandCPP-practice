class Solution{
    int dfs(int n, vector<int> &dp){
        if(n == 0)
            return 0;

        if(dp[n] > -1)
            return dp[n];

        int x = sqrt(n);
        int ret = n;

        for(int i = 1; i <= x; ++i){
            ret = min(ret, dfs(n - i * i, dp) + 1);
        }

        return dp[n] = ret;
    }

public:
    int numSquares(int n){
        vector<int> dp(n + 1, -1);

        return dfs(n, dp);
    }
};
