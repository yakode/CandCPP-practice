class Solution{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth){
        vector<string> ans;
        string s = "";
        int len = words[0].size();
        int i = 0, j;

        for(j = 1; j < words.size(); ++j){
            if(len + 1 + words[j].size() <= maxWidth){
                len += (1 + words[j].size());
            }else{
                // i ~ (j - 1)
                int nr = j - i;
                int space = maxWidth - len + nr - 1;
                s += words[i];
                for(int k = i + 1, l = 1; k < j; ++k, ++l){
                    int tmp = space / (nr - l) + (space % (nr - l) != 0);
                    space -= tmp;
                    s += string(tmp, ' ');
                    s += words[k];
                }
                if(s.size() != maxWidth)
                    s += string(maxWidth - s.size(), ' ');
                ans.push_back(s);
                len = words[j].size();
                s = "";
                i = j;
            }
        }
        for(; i < j; ++i){
            s += words[i];
            if(s.size() < maxWidth)
                s += " ";
        }
        if(s.size() != maxWidth)
            s += string(maxWidth - s.size(), ' ');
        ans.push_back(s);

        return ans;
    }
};
