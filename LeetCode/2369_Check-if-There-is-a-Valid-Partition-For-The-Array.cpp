class Solution{
    bool dfs(int i, vector<int> &nums, vector<int> &dp){
        if(i == nums.size())
            return true;
        if(i > nums.size() - 2)
            return false;

        if(dp[i] != -1)
            return dp[i];

        bool ret = false;
        if(nums[i] == nums[i + 1])
            ret |= dfs(i + 2, nums, dp);
        if(i + 2 < nums.size())
            if((nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) || (nums[i] == nums[i + 1] - 1 && nums[i + 1] == nums[i + 2] -1 ))
                ret |= dfs(i + 3, nums, dp);

        return dp[i] = ret;
    }

public:
    bool validPartition(vector<int> &nums){
        vector<int> dp(nums.size() + 1, -1);

        return dfs(0, nums, dp);
    }
};
