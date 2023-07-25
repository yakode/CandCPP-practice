class Solution{
    void dfs(int i, int n, int k, vector<int> &tmp, vector<vector<int>> &ans){
        if(k == 0){
            ans.push_back(tmp);
            return;
        }
        if(i > n)
            return;
		if(n - i + 1 < k)
			return;

        dfs(i + 1, n, k, tmp, ans);
        tmp[tmp.size() - k] = i;
        dfs(i + 1, n, k - 1, tmp, ans);   
    }

public:
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> ans;
        vector<int> tmp(k);

        dfs(1, n, k, tmp, ans);

        return ans;
    }
};
