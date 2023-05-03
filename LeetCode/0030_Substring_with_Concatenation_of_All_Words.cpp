// brute force...
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        sort(words.begin(), words.end());

        for(int k = 0; k < words[0].size(); ++k){
            int pos[5000], cur = s.size(), cnt = 0;
            memset(pos, -1, sizeof(pos));

            for(int i = k; i < (s.size() - words[0].size() + 1); i += words[0].size()){
                bool flag = false;

                for(int j = 0; j < words.size(); ++j){
                    if(j+1 < words.size() && words[j] == words[j+1] && pos[j] >= cur) continue;

                    if(s[i] == words[j][0] && words[j].compare(s.substr(i, words[j].size())) == 0){
                        if(pos[j] >= cur){
                            int tmp = cur;
                            int ptr = j;

                            while(ptr > 0 && words[ptr] == words[ptr-1]){
                                ptr--;
                                if(pos[ptr] >= cur && pos[ptr] < pos[j]){
                                    j = ptr;
                                }
                            }

                            cur = pos[j] + words[0].size();
                            cnt -= (cur - tmp) / words[0].size();
                        }

                        if(cur == s.size()) cur = i;

                        cnt++;
                        flag = true;
                        pos[j] = i;
                        break;
                    }
                }

                if(!flag){
                    cur = s.size();
                    cnt = 0;
                }else if(cnt == words.size()){
                    ans.push_back(cur);
                    cur += words[0].size();
                    cnt -= 1;
                }
            }
        }

        return ans;
    }
};
