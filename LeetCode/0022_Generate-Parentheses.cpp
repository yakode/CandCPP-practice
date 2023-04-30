class Solution {
public:
    void dfs(int l, int r, int n, string s, vector<string> &ans){
        if(r == n){
            ans.push_back(s);
            return;
        }
        
        if(l > r) dfs(l, r+1, n, s+')', ans);
        if(l < n) dfs(l+1, r, n, s+'(', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        dfs(0, 0, n, "", ans);

        return ans;
    }
};
