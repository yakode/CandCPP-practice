class Solution{
    void dfs(int i, int n, int k, vector<int> &tmp, vector<vector<int>> &ans){
        if(k == 0){
            if(n == 0){
                ans.push_back(tmp);
            }
            return;
        }
        if(i > 9 || (9 - i + 1) < k || n <= 0)
            return;

        dfs(i + 1, n, k, tmp, ans);
        tmp[tmp.size() - k] = i;
        dfs(i + 1, n - i, k - 1, tmp, ans);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> ans;
        vector<int> tmp(k);

        dfs(1, n, k, tmp, ans);

        return ans;
    }
};
