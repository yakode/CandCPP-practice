class Solution{
    int nl[26] = {0}, nr[26] = {0};
    int len = 0;
    
    void dfs(int i, int l, int r, string s, string tmp, set<string> &ans){
        if(i == s.size()){
            if(l == r && (ans.size() == 0 || tmp.size() == len)){
                ans.insert(tmp);
                len = tmp.size();
            }
            return;
        }

        if(s[i] == '('){
            if(nr[s.size()] - nr[i] > 0) dfs(i + 1, l + 1, r, s, tmp + '(', ans);
            if(l - r + nl[s.size()] - nl[i] > nr[s.size()] - nr[i]) dfs(i + 1, l, r, s, tmp, ans);
        }else if(s[i] == ')'){
            if(l > r) dfs(i + 1, l, r + 1, s, tmp + ')', ans);
            if(l - r < nr[s.size()] - nr[i]) dfs(i + 1, l, r, s, tmp, ans);
        }else{
            dfs(i + 1, l, r, s, tmp + s[i], ans);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s){
        set<string> ans;

        for(int i = 1, l = 0, r = 0; i <= s.size(); ++i){
            nl[i] = nl[i - 1];
            nr[i] = nr[i - 1];
            if(s[i - 1] == '('){
                nl[i]++;
            }else if(s[i - 1] == ')'){
                nr[i]++;
            }
        }

        dfs(0, 0, 0, s, "", ans);

        return vector<string>(ans.begin(), ans.end());
    }
};
