class Solution{
public:
    int maxCount(vector<int> &banned, int n, int maxSum){
        int nr = 0;

        sort(banned.begin(), banned.end());
        for(int i = 1, j = 0; i <= n; ++i){
            while(j < banned.size() && i > banned[j])
                ++j;
            if(j < banned.size() && i == banned[j]){
                ++j;
                continue;
            }
            if(maxSum - i >= 0){
                ++nr;
                maxSum -= i;
            }else{
                break;
            }
        }

        return nr;
    }
};
