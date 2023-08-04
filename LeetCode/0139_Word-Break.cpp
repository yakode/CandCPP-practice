class Solution{
    bool dfs(string s, vector<string> &wordDict, vector<int> &dp){
        int n = s.size(), m;

        if(n == 0)
            return true;

        if(dp[n] >= 0)
            return dp[n];

        for(int i = 0; i < wordDict.size(); ++i){
            m = wordDict[i].size();
            if(s.size() >= m && s.substr(0, m) == wordDict[i]){
                if(dfs(s.substr(m, n - m), wordDict, dp)){
                    return dp[n] = true;
                }
            }
        }
        
        return dp[n] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict){
        vector<int> dp(s.size() + 1, -1);

        return dfs(s, wordDict, dp);
    }
};
