class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for(int i = 0, j =0; i < g.size() && j < s.size(); ++i){
            while(j+1 < s.size() && g[i] > s[j]) j++;
            if(g[i] <= s[j]){
                ans++;
                j++;
            }else{
                return ans;
            }
        }

        return ans;
    }
};
