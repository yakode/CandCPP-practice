// brute force
class Solution{
public:
    void dfs(int i, vector<int> &cookies, int k, vector<int> &distribution, int &ans){
        if(i == cookies.size()){
            ans = min(ans, *max_element(distribution.begin(), distribution.end()));
            return;
        }

        for(int j = 0; j < k; ++ j){
            if(distribution[j] + cookies[i] >= ans) continue;
            distribution[j] += cookies[i];
            dfs(i + 1, cookies, k, distribution, ans);
            distribution[j] -= cookies[i];
        }
    }

    int distributeCookies(vector<int> &cookies, int k){
        int ans = INT_MAX;
        vector<int> distribution(k, 0);

        dfs(0, cookies, k, distribution, ans);

        return ans;
    }
};
