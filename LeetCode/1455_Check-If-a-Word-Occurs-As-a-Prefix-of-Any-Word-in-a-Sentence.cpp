class Solution{
public:
    int isPrefixOfWord(string sentence, string searchWord){
        int ans = 1;
        int i = 0;

        for(auto &c: sentence){
            if(c == ' '){
                ans++;
                i = 0;
                continue;
            }
            if(i == -1)
                continue;
            if(c == searchWord[i]){
                i++;
                if(i == searchWord.size())
                    return ans;
            }else{
                i = -1;
            }
        }

        return -1;
    }
};
