class Solution{
public:
    int dp[1000+5][1000+5];

    int lcs(int i, int j, string &text1, string &text2){
        if(i == text1.size() || j == text2.size()) return 0;

        if(dp[i][j] > -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = lcs(i + 1, j + 1, text1, text2) + 1;
        return dp[i][j] = max(lcs(i + 1, j, text1, text2), lcs(i, j + 1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2){
        memset(dp, -1, sizeof(dp));

        return lcs(0, 0, text1, text2);
    }
};
