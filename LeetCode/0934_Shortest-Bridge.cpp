class Solution{
public:
    const int dx[4] = {0, 0, -1, 1},
              dy[4] = {-1, 1, 0, 0};

    void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<int, int>> &q){
        if(i < 0 || i == grid.size() || j < 0 || j == grid.size()) return;
        if(grid[i][j] == -1 || grid[i][j] == 0) return;

        grid[i][j] = -1;
        q.push(make_pair(i, j));
        for(int k = 0; k < 4; ++k)
            dfs(i + dx[k], j + dy[k], grid, q);
    }

    int shortestBridge(vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        int ans = -1;

        for(int i = 0; q.empty(); ++i)
            for(int j = 0; j < grid.size(); ++j)
                if(grid[i][j] == 1){
                    dfs(i, j, grid, q);
                    break;
                }

        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i < 0 || i == grid.size() || j < 0 || j == grid.size()) continue;

                if(grid[i][j] == 2) continue;
                if(grid[i][j] == 1) return ans;

                grid[i][j] = 2;

                for(int k = 0; k < 4; ++k)
                    q.push(make_pair(i + dx[k], j + dy[k]));
            }

            ans++;
        }

        return -1;
    }
};
