class Solution{
    int dx[4] = {0, 0, -1, 1},
        dy[4] = {1, -1, 0, 0};
    
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int step, int target){
        if(i == grid.size() || j == grid[0].size() || i < 0 || j < 0)
            return 0;
        if(grid[i][j] == 2 && step == target)
            return 1;
        if(grid[i][j] == 2)
            return 0;
        if(grid[i][j] == -1 || grid[i][j] == 3)
            return 0;

        grid[i][j] = 3;
        int ret = 0;
        for(int k = 0; k < 4; ++k)
            ret += dfs(i + dx[k], j + dy[k], grid, dp, step + 1, target);
        grid[i][j] = 0;

        return dp[i][j] = ret;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid){
        int x, y;
        int target = 0;
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));

        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }else if(grid[i][j] == 0){
                    ++target;
                }
            }
        }

        return dfs(x, y, grid, dp, 0, target + 1);;
    }
};
