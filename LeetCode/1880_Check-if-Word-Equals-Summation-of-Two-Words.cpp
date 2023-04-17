class Solution {
public:
    int s2i(string &s){
        int num = 0;
        for(int i = 0; i < s.size(); ++i){
            num = num * 10 + (s[i] - 'a');
        }
        return num;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        if(s2i(firstWord) + s2i(secondWord) == s2i(targetWord)) return true;
        return false;
    }
};
