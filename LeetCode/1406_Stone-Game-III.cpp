class Solution{
public:
    int dp[50005] = {0};

    int dfs(int i, vector<int> &nums){
        if(i == nums.size()) return 0;

        if(dp[i] != 0) return dp[i];

        int sum = 0;
        int tmp = INT_MIN;
        for(int x = 1; x <= 3 && (i + x) <= nums.size(); ++x){
            sum += nums[i + x - 1];
            tmp = max(tmp, sum - dfs(i + x, nums));
        }

        return dp[i] = tmp;
    }

    string stoneGameIII(vector<int> &stoneValue){ 
        int ret = dfs(0, stoneValue);

        if(ret > 0) return "Alice";
        else if(ret < 0) return "Bob";
        else return "Tie";
    }
};
