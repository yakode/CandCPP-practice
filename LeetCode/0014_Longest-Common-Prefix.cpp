class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int i = 0;
        for(i = 0; i < strs[0].size(); ++i){
            char c = strs[0][i];
            for(int j = 1; j < n; ++j){
                if(strs[j].size() == i) return strs[0].substr(0, i);
                else if(strs[j][i] != c) return strs[0].substr(0, i);
            }
        }

        return strs[0].substr(0, i);
    }
};
