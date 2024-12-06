class Solution{
public:
    int dfs(vector<vector<int>> &dp, bool corner, int n){
        if(n == 0){
            if(!corner) return dp[corner][n] = 1;
            else return dp[corner][n] = 0;
        }else if(n < 0){
            return 0;
        }

        if(dp[corner][n] > -1)
            return dp[corner][n];

        if(corner){
            // XOOO...
            // OOOO...
            return dp[corner][n] = (dfs(dp, 0, n - 1) + dfs(dp, 1, n - 1)) % (int)(1e9 + 7);
        }else{
            // OOO...
            // OOO...
            dp[corner][n] = (dfs(dp, 0, n - 1) + dfs(dp, 0, n - 2)) % (int)(1e9 + 7);
            dp[corner][n] = (dp[corner][n] + dfs(dp, 1, n - 2)) % (int)(1e9 + 7);
            dp[corner][n] = (dp[corner][n] + dfs(dp, 1, n - 2)) % (int)(1e9 + 7);
            return dp[corner][n];
        }
    }

    int numTilings(int n) {
        vector<vector<int>> dp(2, vector<int>(n + 1, -1));

        return dfs(dp, 0, n);
    }
};
