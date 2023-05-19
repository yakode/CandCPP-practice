class Solution{
public:
    bool isBipartite(vector<vector<int>>& graph){
        int color[105] = {0};
        stack<int> s;
        s.push(0);

        for(int i = 0; i < graph.size(); ++i){
            if(color[i] == 0 && graph[i].size() > 0){
                s.push(i);
                color[i] = 1;
            }
            
            while(!s.empty()){
                int u = s.top();
                s.pop();
                
                for(int v = 0; v < graph[u].size(); ++v){
                    if(color[graph[u][v]] == 0)
                        s.push(graph[u][v]);
                    else if(color[graph[u][v]] == color[u])
                        return false;
                    
                    color[graph[u][v]] = -1 * color[u];
                }
            }
        }
        
        return true;
    }
};
