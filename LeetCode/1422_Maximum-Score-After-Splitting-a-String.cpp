class Solution{
public:
    int maxScore(string s){
        int ans;
        int one = 0;
        int one_right;

        for(auto &c: s)
            if(c == '1')
                ++one;
                
        one_right = one;
        if(s[0] == '1')
            ans = --one_right;
        else
            ans = 1 + one_right; 
        for(int i = 1; i < s.size() - 1; ++i){
            if(s[i] == '1')
                --one_right;
            ans = max(ans, i + 1 + one_right - one + one_right);
        }

        return ans;
    }
};
