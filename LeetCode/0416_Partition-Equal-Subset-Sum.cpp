class Solution{
    bool dfs(int i, vector<int> &nums, int target, vector<vector<int>> &dp){
        if(target == 0)
            return true;

        if(target < 0)
            return false;

        if(i == nums.size())
            return false;

        if(dp[i][target] > -1)
            return dp[i][target];

        return dp[i][target] = dfs(i + 1, nums, target, dp) || dfs(i + 1, nums, target - nums[i], dp);
    }

public:
    bool canPartition(vector<int> &nums){
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum / 2 + 1, -1));

        if(sum % 2 == 1)
            return false;

        return dfs(0, nums, sum / 2, dp);
    }
};
