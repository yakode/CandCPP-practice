class Solution{
public:
    bool isVisited[200] = {0};

    void dfs(int i, vector<vector<int>>& isConnected){
        if(isVisited[i]) return;

        isVisited[i] = true;

        for(int j = 0; j < isConnected.size(); ++j)
            if(isConnected[i][j] == 1)
                dfs(j, isConnected);
    }

    int findCircleNum(vector<vector<int>>& isConnected){
        int ans = 0;

        for(int i = 0; i < isConnected.size(); ++i){
            if(!isVisited[i]){
                ans++;
                dfs(i, isConnected);
            }
        }

        return ans;
    }
};
