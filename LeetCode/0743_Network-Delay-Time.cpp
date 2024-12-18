class Solution{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k){
        vector<vector<int>> edges(n, vector<int>(n, INT_MAX));
        for(auto &e: times){
            edges[e[0] - 1][e[1] - 1] = e[2];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1});
        
        set<int> s;
        for(int i = 0; i < n; ++i){
            s.insert(i);
        }

        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        
        while(!pq.empty()){
            while(!pq.empty() && s.count(pq.top().second) == 0)
                pq.pop();
            if(pq.empty())
                break;
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            s.erase(u);

            for(auto &v: s){
                if(edges[u][v] != INT_MAX && dist[u] + edges[u][v] < dist[v]){
                    dist[v] = dist[u] + edges[u][v];
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for(auto &w: dist){
            ans = max(ans, w);
            if(w == INT_MAX)
                return -1;
        }

        return ans;
    }
};
