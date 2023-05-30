class Solution{
public:
    string minWindow(string s, string t){
        int cnt[128] = {0};
        bool flag[128] = {0};
        for(int i = 0; i < t.size(); ++i){
            flag[t[i]] = true;
            cnt[t[i]]++;
        }

        int ans[2] = {(int)(s.size() + 1), 0};
        // answer is s[ans[1]] ~ s[ans[1] + ans[0]]
        int cur = 0;
        int check = 0;
        for(int i = 0; i < s.size(); ++i){
            if(flag[s[i]]){
                cnt[s[i]]--;

                if(cnt[s[i]] >= 0) check++;

                while(cur <= i){
                    if(flag[s[cur]] && cnt[s[cur]] >= 0){
                        // this char is needed
                        break;
                    }
                    cnt[s[cur++]]++;
                }

                if(check == t.size() && ans[0] > (i - cur + 1)){
                    ans[0] = i - cur + 1;
                    ans[1] = cur;
                }
            } 
        }

        if(check == t.size()) return s.substr(ans[1], ans[0]);
        return "";
    }
};
