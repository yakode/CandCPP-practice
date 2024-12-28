class Solution{
public:
    int longestValidParentheses(string s){
        vector<int> tmp(s.size(), 0);
        stack<int> left;

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                left.push(i);
            }else{
                if(!left.empty()){
                    tmp[i] = 1;
                    tmp[left.top()] = 1;
                    left.pop();
                }
            }
        }

        int ans = 0;
        int cur = 0;
        
        for(int i = 0; i < s.size(); ++i){
            if(tmp[i] == 1){
                ++cur;
            }else{
                if(cur > ans)
                    ans = cur;
                cur = 0;
            }
        }
        if(cur > ans)
            ans = cur;

        return ans;
    }
};
