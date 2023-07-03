class Solution{
public:
    bool buddyStrings(string s, string goal){
        int cnt = 0, buf[2];
        int hash[26] = {0};

        for(int i = 0; i < goal.size(); ++i){
            hash[goal[i] - 'a']++;
            if(goal[i] != s[i]){
                if(cnt == 2) return false;
                buf[cnt] = i;
                cnt++;
            }
        }
        if(cnt == 1) return false;
        if(cnt == 2){
            swap(goal[buf[0]], goal[buf[1]]);
            if(goal == s) return true;
            else return false;
            swap(goal[buf[0]], goal[buf[1]]);
        }
        for(int i = 0; i < 26; ++i){
            if(hash[i] >= 2) return true;
        }
        
        return false;
    }
};
