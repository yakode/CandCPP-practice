class Solution{
    int dfs(int i, bool head, vector<int> &nums, vector<vector<int>> &dp){
        if(i == nums.size())
            return 0;

        if(dp[head][i] > -1)
            return dp[head][i];

        if(i == nums.size() - 1){
            if(head && i > 0)
                return 0;
            else
                return nums[i];
        }

        return dp[head][i] = max(dfs(i + 1, head, nums, dp), dfs(i + 2, head, nums, dp) + nums[i]);
    }

public:
    int rob(vector<int> &nums){
        vector<vector<int>> dp(2, vector<int>(nums.size() + 1, -1));

        return max(dfs(0, true, nums, dp), dfs(1, false, nums, dp));
    }
};
