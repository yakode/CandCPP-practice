class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid){
        // reach the boundary
        if(x < 0 || x > grid.size()-1 || y < 0 || y > grid[x].size()-1) return -1; 
	// not the land
        if(grid[x][y] == 0) return 0;
        // avoid repeated walk
        grid[x][y] = 0;

        int dx[4] = {0, 0, -1, 1},
            dy[4] = {-1, 1, 0, 0};
        int ret = 1, tmp = 0;
        for(int i = 0; i < 4; ++i){
            tmp = dfs(x+dx[i], y+dy[i], grid);
            if(tmp < 0 || ret < 0) ret = -1;
            else ret += tmp;
        }

        return ret;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int tmp = 0, ans = 0;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    tmp = dfs(i, j, grid);
                    if(tmp > 0) ans += tmp;
                }
            }
        }

        return ans;
    }
};
