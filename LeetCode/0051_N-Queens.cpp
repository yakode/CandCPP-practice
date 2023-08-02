class Solution{
    bool check(int i, int j, vector<string> &pos){
        int n = pos.size();

        for(int s = 0; s < i; ++s)
            if(pos[s][j] == 'Q')
                return false;
        for(int s = i - 1, t = j + 1; s >= 0 && t < n; --s, ++t)
            if(pos[s][t] == 'Q')
                return false;
        for(int s = i - 1, t = j - 1; s >= 0 && t >= 0; --s, --t)
            if(pos[s][t] == 'Q')
                return false;
        return true;        
    }

    void dfs(int i, vector<string> &pos, vector<vector<string>> &ans){
        int n = pos.size();

        if(i == pos.size()){
            ans.push_back(pos);
        }

        for(int j = 0; j < n; ++j){
            if(check(i, j, pos)){
                pos[i][j] = 'Q';
                dfs(i + 1, pos ,ans);
                pos[i][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;
        vector<string> pos(n);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                pos[i] += '.';

        dfs(0, pos, ans);

        return ans;
    }
};
