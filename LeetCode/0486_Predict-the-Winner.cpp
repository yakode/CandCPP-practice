class Solution{
    int dp[2][25][25] = {0};

    int dfs(int i, int j, bool player1, vector<int> &nums){
        if(i > j)
            return 0;

        if(dp[player1][i][j] > 0)
            return dp[player1][i][j];
        
        if(player1)
            return dp[player1][i][j] = max(dfs(i + 1, j, !player1, nums) + nums[i], dfs(i, j - 1, !player1, nums) + nums[j]);
        return dp[player1][i][j] = min(dfs(i + 1, j, !player1, nums) - nums[i], dfs(i, j - 1, !player1, nums) - nums[j]);
    }
    
public:
    bool PredictTheWinner(vector<int> &nums){
        return dfs(0, nums.size() - 1, true, nums) >= 0;
    }
};
