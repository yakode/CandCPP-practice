class Solution{
    int dfs(int i, vector<int> &nums, int target, vector<vector<int>> &dp){
        if(i == nums.size()){
            if(target == 0)
                return 1;
            return 0;
        }

        if(target < 0)
            return 0;

        if(dp[i][target] > -1)
            return dp[i][target];
        
        return dp[i][target] = dfs(i + 1, nums, target, dp) + dfs(i + 1, nums, target - nums[i], dp);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target){
        target += accumulate(nums.begin(), nums.end(), 0);
        if(target % 2 == 1 || target < 0)
            return 0;
        target /= 2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));

        return dfs(0, nums, target, dp);
    }
};
