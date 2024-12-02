class Solution{
public:
    int minimumObstacles(vector<vector<int>> &grid){
        int step = 0;
        const int dx[4] = {0, 0, -1, 1},
                  dy[4] = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        
        q.push(make_pair(0, 0));
        visited[0][0] = true;

        while(!q.empty()){
            int nr = q.size();

            while(nr--){
                queue<pair<int, int>> q2;
                q2.push(make_pair(q.front().first, q.front().second));
                q.pop();

                while(!q2.empty()){
                    int x = q2.front().first, y = q2.front().second;
                    q2.pop();
                    
                    for(int i = 0; i < 4; ++i){
                        int x2 = x + dx[i], y2 = y + dy[i];
                        if(x2 < 0 || x2 >= grid.size()) continue;
                        if(y2 < 0 || y2 >= grid[0].size()) continue;
                        if(!visited[x2][y2]){
                            if(x2 == grid.size() - 1 && y2 == grid[0].size() - 1)
                                return step;
                            if(grid[x2][y2] == 0)
                                q2.push(make_pair(x2, y2));
                            else
                                q.push(make_pair(x2, y2));
                            visited[x2][y2] = true;
                        }
                    }
                }
            }
            step++;
        }

        return 0;
    }
};
