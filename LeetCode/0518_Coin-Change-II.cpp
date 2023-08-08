class Solution{
    int dfs(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0)
            return 1;

        if(amount < 0)
            return 0;
        
        if(i == coins.size())
            return 0;

        if(dp[i][amount] > -1)
            return dp[i][amount];

        return dp[i][amount] = dfs(i, amount - coins[i], coins, dp) + dfs(i + 1, amount, coins, dp);
    }

public:
    int change(int amount, vector<int> &coins){
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        return dfs(0, amount, coins, dp);
    }
};
