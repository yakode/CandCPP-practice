class Solution {
public:
    vector<string> ans;
    vector<string> letter = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string &digits, int pos, string tmp){
        if(pos == digits.size()){
            ans.push_back(tmp);
            return;
        }

        for(int i = 0; i < letter[digits[pos]-'2'].size(); ++i){
            dfs(digits, pos+1, tmp+letter[digits[pos]-'2'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() > 0) dfs(digits, 0, "");

        return ans;
    }
};
