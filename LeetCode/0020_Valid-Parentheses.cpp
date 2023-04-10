class Solution {
public:
    bool isValid(string s) {
        stack<char> leftpart;
        int S = s.size();
        for(int i = 0; i < S; ++i){
            if(s[i] == '(' || s[i] == '['  || s[i] == '{'){
                leftpart.push(s[i]);
            }else{
                if(leftpart.empty()) return false;
                char p = leftpart.top();
                leftpart.pop();
                if(p == '(' && s[i] != ')') return false;
                else if(p == '[' && s[i] != ']') return false;
                else if(p == '{' && s[i] != '}') return false;
            }
        }
        if(!leftpart.empty()) return false;
        return true;
    }
};
