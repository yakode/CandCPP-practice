class Solution {
public:
    int dp[105][105][105] = {0};
    int M = 1e9 + 7;

    int dfs(int i, int n, int np, vector<int>& group, vector<int>& profit){
        // If there are n people and crimes[i:], what is the profitable scheme with the minProfit = np?
        if(n < 0){
            // no people no profit :p
            return 0;
        }
        
        // dp[i][n][-1] == dp[i][n][0]
        // if np <= 0, profit >= np no matter how people choose what to do.
        if(np <= 0) np = 0;
        if(dp[i][n][np] >= 0) return dp[i][n][np];

		// If no crime to do or no people to use, we can not earn more profit.
        if(i >= group.size() || n == 0){
            if(np <= 0) dp[i][n][np] = 1;
            else dp[i][n][np] = 0;
            return dp[i][n][np];
        }
        
        dp[i][n][np] = (dfs(i+1, n-group[i], np-profit[i], group, profit) + dfs(i+1, n, np, group, profit)) % M;
        return dp[i][n][np];
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, n, minProfit, group, profit);
    }
};
