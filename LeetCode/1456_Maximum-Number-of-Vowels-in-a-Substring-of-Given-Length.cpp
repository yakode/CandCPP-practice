class Solution {
public:
    bool isVowel(const char &c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int cur = 0, ans = 0;

        int i;
        for(i = 0; i < k; ++i){
            if(isVowel(s[i])) cur++;
        }
        ans = cur;

        for(; i < s.size(); ++i){
            if(isVowel(s[i]) && !isVowel(s[i-k])){
                cur++;
                if(cur > ans) ans = cur;
            }else if(isVowel(s[i-k]) && !isVowel(s[i])) cur--;
        }

        return ans;
    }
};
