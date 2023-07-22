class Solution{
    void dfs(int i, string &s, vector<string> &ans){
        if(i == s.size()){
            ans.push_back(s);
            return;
        }

        if(s[i] >= '0' && s[i] <= '9'){
            dfs(i + 1, s, ans);
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            dfs(i + 1, s, ans);
            s[i] -= ('a' - 'A');
            dfs(i + 1, s, ans);
            s[i] += ('a' - 'A');
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            dfs(i + 1, s, ans);
            s[i] += ('a' - 'A');
            dfs(i + 1, s, ans);
            s[i] -= ('a' - 'A');
        }
    }

public:
    vector<string> letterCasePermutation(string s){
        vector<string> ans;

        dfs(0, s, ans);

        return ans;
    }
};
