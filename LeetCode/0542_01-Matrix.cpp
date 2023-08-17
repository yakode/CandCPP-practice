class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));
        queue<pair<int, int>> q;
        int dx[4] = {0, 0, -1, 1},
        dy[4] = {1, -1, 0, 0};

        for(int i = 0; i < mat.size(); ++i){
            for(int j = 0; j < mat[0].size(); ++j){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }else{
                    ans[i][j] = INT_MAX;
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat[0].size() || ans[nx][ny] <= ans[x][y] + 1)
                    continue;
                ans[nx][ny] = ans[x][y] + 1;
                q.push({nx, ny});
            }
        }

        return ans;
    }
};
