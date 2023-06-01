class Solution{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid){
        int n = grid.size();
        queue<pair<int, int>> q;
        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1},
            dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        int ans = 0;

        if(grid[0][0] == 1) return -1;

        grid[0][0] = 1;
        q.push(make_pair(0, 0));

        while(!q.empty()){
            ans++;

            int s = q.size();
            while(s--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == n-1 && y == n-1) return ans;

                for(int i = 0; i < 8; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        if(grid[nx][ny] == 0){
                            grid[nx][ny] = 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }

        return -1;
    }
};
