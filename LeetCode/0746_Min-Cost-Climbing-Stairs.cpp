class Solution{
    int dfs(int i, vector<int> &cost, vector<int> &dp){
        if(i >= cost.size())
            return 0;

        if(dp[i] > 0)
            return dp[i];

        return dp[i] = cost[i] + min(dfs(i + 1, cost, dp), dfs(i + 2, cost, dp));
    }
    
public:
    int minCostClimbingStairs(vector<int> &cost){
        vector<int> dp(cost.size() + 1, -1);

        cost.insert(cost.begin(), 0);

        return dfs(0, cost, dp);
    }
};
