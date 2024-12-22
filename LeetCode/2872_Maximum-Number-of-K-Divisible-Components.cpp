class Solution{
    int dfs(int root, int k, vector<vector<int>> &tree, vector<int> &values, vector<bool> &visited, int &ans){
        int sum = values[root];

        visited[root] = true;
        for(auto &i: tree[root]){
            if(!visited[i]){
                sum += dfs(i, k, tree, values, visited, ans);
                sum %= k;
            }
        }

        if(sum % k == 0){
            ++ans;
            return 0;
        }
        return sum % k;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k){
        int ans = 0;
        vector<vector<int>> tree(n);
        vector<bool> visited(n, false);
        
        for(auto &e: edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(0, k, tree, values, visited, ans);

        return ans;
    }
};
