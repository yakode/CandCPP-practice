class Solution{
public:
    string smallestString(string s){
        int start = s.size() - 1;
        
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != 'a'){
                start = i;
                break;
            }
        }

        if(start == s.size() - 1 && s[start] == 'a')
        {
            s[start] = 'z';
            return s;
        }
             
        for(int i = start; i < s.size(); ++i){
            if(s[i] == 'a'){
                break;
            }
            s[i] -= 1;
        }
        
        return s;
    }
};
