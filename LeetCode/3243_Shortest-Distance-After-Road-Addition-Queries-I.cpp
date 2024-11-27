class Solution{
    int bfs(int n, bool **edges){
        queue<int> q;
        int step = 0;
        bool visited[500] = {0};

        q.push(0);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                int x = q.front();
                q.pop();
                if(x == (n - 1))
                    return step;
                for(int j = x + 1; j < n; ++j){
                    if(edges[x][j] && !visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            step++;
        }

        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries){
        vector<int> ans(queries.size(), 1);
        bool **edges = new bool*[n];
        for(int i = 0; i < n; ++i){
            edges[i] = new bool[n];
            for(int j = 0; j < n; ++j)
                edges[i][j] = false;
            if(i != (n - 1))
                edges[i][i + 1] = true;
        }

        for(int i = 0; i < queries.size(); ++i){
            edges[queries[i][0]][queries[i][1]] = true;
            ans[i] = bfs(n, edges);
            if(ans[i] == 1)
                break;
        }

        return ans;
    }
};
