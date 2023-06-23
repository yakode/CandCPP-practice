class Solution{
private:
    int dp[1000][1001] = {0};
public:
    int longestArithSeqLength(vector<int> &nums){
        int ans = 0;

        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = dp[j][diff] + 1;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans + 1;
    }
};
