class Solution{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads){
        vector<vector<bool>> connected(n, vector<bool>(n, 0));
        vector<pair<int, int>> edge(n, {0, 0});
        int ans = 0;

        for(int i = 0; i < n; ++i)
            edge[i].second = i;

        for(int i = 0; i < roads.size(); ++i){
            ++edge[roads[i][0]].first;
            ++edge[roads[i][1]].first;
            connected[roads[i][0]][roads[i][1]] = true;
            connected[roads[i][1]][roads[i][0]] = true;
        }

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int sum = edge[i].first + edge[j].first - connected[edge[i].second][edge[j].second];
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
