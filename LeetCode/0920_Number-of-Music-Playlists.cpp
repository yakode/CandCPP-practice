class Solution{
    int mod = 1e9 + 7;
    
    int dfs(int n, int goal, int k, int used, vector<vector<int>> &dp){
        long long ans = 0;
        
        if(goal == 0){
            if(used == n)
                return 1;
            return 0;
        }
        if(used > n)
            return 0;

        if(dp[goal][used] > -1)
            return dp[goal][used];

        ans += dfs(n, goal - 1, k, used + 1, dp) * (long long)(n - used);
        ans %= mod;
        if(used > k)
            ans += dfs(n, goal - 1, k, used, dp) * (long long)(used - k);

        return dp[goal][used] = (ans % mod);
    }

public:
    int numMusicPlaylists(int n, int goal, int k){
        vector<vector<int>> dp(goal + 1, vector<int>(n + 1, -1));

        return dfs(n, goal, k, 0, dp);
    }
};
