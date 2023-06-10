class Solution{
public:
    int longestSemiRepetitiveSubstring(string s){
        int ans = 1, cur = 0, i, pos = -1;

        for(i = 1; i < s.size(); ++i){
            if(i > cur && s[i] == s[i - 1]){
                if(pos >= cur){
                    // reset        
                    ans = max(ans, (i - cur));
                    cur = pos;
                    pos = i;
                }else{
                    pos = i;
                }
            }
        }

        ans = max(ans, (i - cur));
        
        return ans;
    }
};
