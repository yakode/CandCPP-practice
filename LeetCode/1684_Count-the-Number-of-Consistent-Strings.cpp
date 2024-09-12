class Solution{
public:
    int countConsistentStrings(string allowed, vector<string> &words){
        int ans = 0;
        bool check[26] = {0};
        
        for(auto &c: allowed)
            check[c - 'a'] = 1;

        for(string &s: words){
            ans++;
            for(char &c: s){
                if(!check[c - 'a']){
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};
