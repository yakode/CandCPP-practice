class Solution{
    int dfs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == s1.size())
            return s2.size() - j;
        if(j == s2.size())
            return s1.size() - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = dfs(i + 1, j + 1, s1, s2, dp);
        return dp[i][j] = min(dfs(i + 1, j + 1, s1, s2, dp), min(dfs(i + 1, j, s1, s2, dp), dfs(i, j + 1, s1, s2, dp))) + 1;
    }

public:
    int minDistance(string word1, string word2){
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));

        return dfs(0, 0, word1, word2, dp);
    }
};
