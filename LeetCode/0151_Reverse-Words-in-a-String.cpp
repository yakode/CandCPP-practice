class Solution{
public:
    string reverseWords(string s){
        string ans;
        stack<string> w;

        int i, j;
        for(i = 0, j = 0; j < s.size(); ++j){
            if(s[j] == ' '){
                if(i < j){
                    w.push(s.substr(i, j - i));
                }
                i = j + 1;
            }
        }
        if(s[j - 1] != ' ' && i < j)
            w.push(s.substr(i, j - i));

        while(!w.empty()){
            ans += w.top() + " ";
            w.pop();
        }
        ans.resize(ans.size() - 1);

        return ans;
    }
};
