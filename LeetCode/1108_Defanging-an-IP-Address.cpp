class Solution {
public:
    string defangIPaddr(string address) {
        string ans(address+"112233");

        for(int i = 0, j = 0; i < address.size(); ++i){
            if(address[i] != '.') ans[j++] = address[i];
            else{
                ans[j++] = '[';
                ans[j++] = address[i];
                ans[j++] = ']';
            }
        }

        return ans;
    }
};
