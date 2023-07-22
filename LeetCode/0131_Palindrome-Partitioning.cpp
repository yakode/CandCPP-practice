class Solution{
    void dfs(int i, string &s, vector<string> &item, vector<vector<string>> &ans){
        if(i == s.size()){
            ans.push_back(item);
            return;
        }

        for(int j = i; j < s.size(); ++j){
            bool flag = true;
            for(int u = i, v = j; u <= v; ++u, --v){
                if(s[u] != s[v]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                item.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, item, ans);
                item.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s){
        vector<vector<string>> ans;
        vector<string> item;

        dfs(0, s, item, ans);

        return ans;
    }
};
