class Solution {
    double dp[26][26][101] = {0};
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1},
        dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    double dfs(int x, int y, int n, int k){
        if(x < 0 || x >= n || y < 0 || y >= n)
            return 0;
        if(k == 0)
            return 1;
        if(dp[x][y][k] > 0)
            return dp[x][y][k];

        double ret = 0;
        for(int i = 0; i < 8; ++i){
            ret += 0.125 * dfs(x + dx[i], y + dy[i], n, k - 1);
        }

        return dp[x][y][k] = ret;
        
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        return dfs(row, column, n, k);
    }
};
