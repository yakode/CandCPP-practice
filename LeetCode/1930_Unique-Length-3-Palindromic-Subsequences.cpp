class Solution{
public:
    int countPalindromicSubsequence(string s){
        int ans = 0;
        vector<int> firstpos(26, -1);
        vector<int> lastpos(26, -1);
        vector<bool> counted(26*26*26, 0);

        for(int i = 0; i < s.size(); ++i){
            char c = s[i];

            if(firstpos[c - 'a'] == -1)
                firstpos[c - 'a'] = i;
            
            if(i > firstpos[c - 'a']){
                int tmp = (c - 'a') * 26 * 26 + (c - 'a');
                for(int i = 0; i < 26; ++i){
                    if(lastpos[i] > firstpos[c - 'a'] && !counted[tmp + i * 26]){
                        counted[tmp + i * 26] = true;
                        ++ans;
                    }
                }
            }

            lastpos[c - 'a'] = i;
        }

        return ans;
    }
};
