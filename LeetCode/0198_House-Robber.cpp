class Solution{
    int dfs(int i, vector<int> &nums, vector<int> &dp){
        if(i >= nums.size())
            return 0;

        if(dp[i] > -1)
            return dp[i];

        return dp[i] = max(dfs(i + 1, nums, dp), dfs(i + 2, nums, dp) + nums[i]);
    }

public:
    int rob(vector<int> &nums){
        vector<int> dp(nums.size() + 1, -1);

        return dfs(0, nums, dp);
    }
};
