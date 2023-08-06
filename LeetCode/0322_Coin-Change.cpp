class Solution{
    int dfs(vector<int> &coins, int amount, vector<int> &dp){
        int ret = 10000 + 1;

        if(amount == 0){
            return 0;
        }

        if(dp[amount] > -1)
            return dp[amount];

        for(int i = 0; i < coins.size(); ++i){
            if(coins[i] <= amount){
                ret = min(ret, dfs(coins, amount - coins[i], dp) + 1);
            }
        }

        return dp[amount] = ret;
    }

public:
    int coinChange(vector<int>& coins, int amount){
        int ans;
        vector<int> dp(amount + 1, -1);

        ans = dfs(coins, amount, dp);

        if(ans >= 10001)
            return -1;
        return ans;
    }
};
