class Solution{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph){
        vector<vector<int>> invG(graph.size());
        vector<int> degree(graph.size());

        for(int i = 0; i < graph.size(); ++i){
            degree[i] = graph[i].size();
            for(int j = 0; j < graph[i].size(); ++j){
                invG[graph[i][j]].push_back(i);
            }
        }
        
        vector<int> ans;
        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 0; i < graph.size(); ++i){
                if(degree[i] == 0){
                    degree[i] = -1;
                    ans.push_back(i);
                    flag = true;
                    for(int j = 0; j < invG[i].size(); ++j)
                        --degree[invG[i][j]];
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
