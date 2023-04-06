class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        bool dp[1000+5][1000+5] = {0};
        int ans[3] = {0, -1, -1}; // len, start, end

        /*
            dp[i][j] means if s[i:j] is a palindromic substring
            eg. s = "babad"
            i\j 0 1 2 3 4
            0   1 0 1 0 0
            1   0 1 0 1 0
            2   0 0 1 0 0
            3   0 0 0 1 0
            4   0 0 0 0 1
        */

        for(int d = 0; d < len; ++d){
            for(int i = 0; i+d < len; ++i){
                int j = i + d;
                if(i == j) dp[i][j] = true;
                else if(s[i] == s[j] && (j == i+1 || dp[i+1][j-1])) dp[i][j] = true;
                if(dp[i][j] && j-i+1 > ans[0]){
                    ans[0] = j-i+1;
                    ans[1] = i;
                    ans[2] = j;
                }
            }
        }

        return s.substr(ans[1], ans[0]);
    }
};
