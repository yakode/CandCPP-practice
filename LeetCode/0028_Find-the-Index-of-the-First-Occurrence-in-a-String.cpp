class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;

        for(int i = 0; i < (haystack.size() - needle.size() + 1); ++i){
            if(haystack[i] == needle[0] && needle.compare(haystack.substr(i, needle.size())) == 0){
                return i;
            }
        }

        return -1;
    }
};
