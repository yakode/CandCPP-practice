class Solution {
public:
    long long dp[100000+5];

    long long dfs(int i, vector<vector<int>>& questions){
        if(i >= questions.size()) return 0;
        
        if(dp[i] > -1) return dp[i];

        return dp[i] = max(dfs(i + questions[i][1] + 1, questions) + questions[i][0], dfs(i+1, questions));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));

        return dfs(0, questions);
    }
};
