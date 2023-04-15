class Solution {
public:
    int romanToInt(string s) {
        int val[15] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbol[15] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int ans = 0;

        for(int i = 0, j = 0; i < 13; ++i){
            if(symbol[i].size() == 2){
                if(j+1 < s.size() && s[j] == symbol[i][0] && s[j+1] == symbol[i][1]){
                    ans += val[i];
                    j += 2;
                }
            }else{
                while(symbol[i].size() == 1 && s[j] == symbol[i][0]){
                    ans += val[i];
                    j++;
                }
            }
        }
        
        return ans;
    }
};
