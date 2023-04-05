class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[128];
        memset(pos, -1, 128*sizeof(int));
        int max_sub[3] = {0, -1, -1}; // len, start, end
        int cur_sub[3] = {0, 0, 0};
        int len = s.size();
        for(int i = 0; i < len; ++i){
            int x = s[i];
            if(pos[x] >= cur_sub[1]){
                // repeated char
                if(cur_sub[0] > max_sub[0]){
                    for(int j = 0; j < 3; ++j)
                        max_sub[j] = cur_sub[j];
                }
                cur_sub[1] = pos[x] + 1;
                cur_sub[2] = i;
                cur_sub[0] = cur_sub[2] - cur_sub[1] + 1;
            }else{
                cur_sub[0] += 1;
                cur_sub[2] = i;
            }
            pos[x] = i;
        }
        if(cur_sub[0] > max_sub[0]){
            for(int j = 0; j < 3; ++j)
                max_sub[j] = cur_sub[j];
        }
        return max_sub[0];
    }
};
