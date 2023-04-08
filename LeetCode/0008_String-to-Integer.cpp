class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        int minus = 0;
        int len = s.size();
        
	for(int i = 0; i < len; ++i){
            if(s[i] >= '0' && s[i] <= '9'){
                if(minus == 0) minus = 1;
                ans = ans * 10 + (s[i] - '0');
                if(ans > 2147483647){
                    if(minus == 1) return 2147483647;
                    return -2147483648;
                }
            }else{
                if(ans != 0) return ans * minus;
                if(s[i] == '-' && minus == 0){
                    minus = -1;
                }else if(s[i] == '+' && minus == 0){
                    minus = 1;
                }else if(s[i] == ' ' && minus == 0){
                    continue;
                }else{
                    return 0;
                }
            }
        }

	return ans * minus;
    }
};
