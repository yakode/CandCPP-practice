class Solution{
public:
    bool canMakeSubsequence(string str1, string str2){
        char alp[26];
        for(int i = 0; i < 26; ++i)
            alp[i] = 'a' + i;

        for(int i = 0, j = 0; i < str1.size(); ++i){
            if(str1[i] == str2[j] || alp[(str1[i] - 'a' + 1) % 26] == str2[j]){
                ++j;
                if(j == str2.size())
                    return true;
            }
        }

        return false;
    }
};
