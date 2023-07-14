class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference){
        vector<int> dp(20001, 0);
        int ans = 0;

        for(int i = 0; i < arr.size(); ++i){
            int j = arr[i] + 10000;

            if(dp[j] == 0)
                dp[j] = 1;
            if(j - difference >= 0 && j - difference <= 20000 && dp[j - difference] > 0)
                dp[j] = max(dp[j], dp[j - difference] + 1);

            ans = max(ans, dp[j]);
        }

        if(difference == 0)
            ans -= 1;

        return ans;
    }
};
