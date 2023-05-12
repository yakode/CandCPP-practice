class Solution{
public:
    string countAndSay(int n){
        if(n == 1) return "1";

        string s = countAndSay(n - 1);

        string ans;
        char cur = s[0];
        int cnt = 0;

        for(auto c: s){
            if(c == cur){
                cnt++;
            }else{
                ans += to_string(cnt) + cur;
                cur = c;
                cnt = 1;
            }
        }
        ans += to_string(cnt) + cur;

        return ans;
    }
};
