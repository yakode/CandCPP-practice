class Solution{
public:
    int dp[1000+5][1000+5];

    int dfs(int i, int j, string &s){
        if(i > j) return 0;

        if(dp[i][j] > -1) return dp[i][j];

        if(i == j) return dp[i][j] = (s[i] == s[j]);
        
        if(s[i] == s[j]) return dp[i][j] = dfs(i + 1, j - 1, s) + 2;

        return dp[i][j] = max(dfs(i + 1, j, s), dfs(i, j - 1, s));
    }

    int longestPalindromeSubseq(string s){
        memset(dp, -1, sizeof(dp));

        return dfs(0, s.size() - 1, s);
    }
};
