class Solution{
public:
    string removeDuplicateLetters(string s){
        string ans = "";
        stack<char> buf;
        int pos[26];
        bool isAdd[26] = {0};

        for(int i = 0; i < s.size(); ++i){
            pos[s[i] - 'a'] = i;
        }

        for(int i = 0; i < s.size(); ++i){
            if(!isAdd[s[i] - 'a']){
                while(!buf.empty() && buf.top() > s[i] && pos[buf.top() - 'a'] > i){
                    isAdd[buf.top() - 'a'] = false;
                    buf.pop();
                }
                buf.push(s[i]);
                isAdd[s[i] - 'a'] = true;
            }
        }

        while(!buf.empty()){
            ans += buf.top();
            buf.pop();
        }

        for(int i = 0, j = ans.size() - 1; i < j; ++i, --j){
            swap(ans[i], ans[j]);
        }

        return ans;
    }
};
