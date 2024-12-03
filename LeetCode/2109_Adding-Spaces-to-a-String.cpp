class Solution{
public:
    string addSpaces(string s, vector<int> &spaces){
        string ret = "";
        int i = 0;
        for(int j = 0; j < s.size(); ++j){
            if(i < spaces.size() && j == spaces[i]){
                // insert space before s[j]
                ret.push_back(' ');
                ++i;
            }
            ret.push_back(s[j]);
        }

        return ret;
    }
};
