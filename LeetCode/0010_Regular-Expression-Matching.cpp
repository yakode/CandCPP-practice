class Solution {
public:
    bool isMatch(string s, string p) {
        const int S = s.size(), P = p.size();
        bool dp[25][25] = {0};

        dp[0][0]= true;

        for(int i = 0; i < P; ++ i){
            if(p[i] == '*' || (i != P-1 && p[i+1] == '*')) dp[0][i+1] = dp[0][i];
        }

        for(int i = 1; i < S+1; ++i){
            for(int j = 1; j < P+1; ++j){
                // len(partial s) = i, focus on s[i-1]
                // len(partial p) = j, focus on p[j-1]
                if(j < P && p[j] == '*')
                    dp[i][j] = dp[i][j-1];
                else if(s[i-1] == p[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || (dp[i-1][j] && (p[j-2] == '.' || p[j-2] == s[i-1]));
            }
        }

        return dp[S][P];
    }
};
