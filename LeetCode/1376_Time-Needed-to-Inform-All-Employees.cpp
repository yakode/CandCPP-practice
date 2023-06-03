// dfs
class Solution{
public:
    int dfs(int i, vector<vector<int>> &subordinate, vector<int> &informTime){
        int ret = 0;

        for(int j = 0; j < subordinate[i].size(); ++j){
            ret = max(ret, dfs(subordinate[i][j], subordinate, informTime));
        }

        return ret + informTime[i];
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime){
        vector<vector<int>> subordinate(n);

        for(int i = 0; i < n; ++i){
            if(i == headID) continue;
            subordinate[manager[i]].push_back(i);
        }

        return dfs(headID, subordinate, informTime);
    }
};

// dp
class Solution{
public:
    int dp[100000];

    int dfs(int i, vector<int> &manager, vector<int> &informTime){
        if(manager[i] == -1) return informTime[i];
        if(dp[i] >= 0) return dp[i];
        return dp[i] = dfs(manager[i], manager, informTime) + informTime[i];
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime){
        int ans = 0;
        memset(dp, -1, sizeof(int)*n);

        for(int i = 0; i < n; ++i){
            ans = max(ans, dfs(i, manager, informTime));
        }

        return ans;
    }
};
