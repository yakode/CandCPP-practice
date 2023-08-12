class Solution{
    int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(x == grid.size() - 1 && y == grid[0].size() - 1 && grid[x][y] == 0)
            return 1;
        if(x == grid.size() || y == grid[0].size())
            return 0;
        if(grid[x][y] == 1)
            return 0;

        if(dp[x][y] > -1)
            return dp[x][y];

        return dp[x][y] = dfs(x + 1, y, grid, dp) + dfs(x, y + 1, grid, dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid){
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, -1));

        return dfs(0, 0, obstacleGrid, dp);
    }
};
