class Solution{
public:
    unordered_map<string, unordered_map<string, double>> graph;

    double dfs(string &from, string &to, unordered_set<string> isVisited){
        if(isVisited.count(from)) return -1;

        if(from == to) return 1;
        
        isVisited.insert(from);

        for(const auto &it: graph[from]){
            string mid = it.first;
            double d = dfs(mid, to, isVisited);

            if(d > 0) return d * it.second;
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        vector<double> ans(queries.size());

        for(int i = 0; i < equations.size(); ++i){
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = (double) 1 / values[i];
        }

        for(int i = 0; i < queries.size(); ++i){
            if(graph.count(queries[i][0]) == 0 || graph.count(queries[i][1]) == 0){
                ans[i] = -1;
            }else{
                unordered_set<string> isVisited;
                ans[i] = dfs(queries[i][0], queries[i][1], isVisited);
            }
        }

        return ans;
    }
};
