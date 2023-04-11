class Solution {
public:
    string removeStars(string s) {
        stack<char> buffer;
        int S = s.size();
        for(int i = 0; i < S; ++i){
            if(s[i] == '*' && !buffer.empty()){
                buffer.pop();
            }else{
                buffer.push(s[i]);
            }
        }
        
        string ans = s.substr(0, buffer.size());
        for(int i = buffer.size()-1; i >= 0; --i){
            ans[i] = buffer.top();
            buffer.pop();
        }

        return ans;
    }
};
