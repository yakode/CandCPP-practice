class Solution{
public:
    int hIndex(vector<int> &citations){
        int ans = 0;
        int n = citations.size();

        sort(citations.begin(), citations.end());

        for(int i = 0; i < citations.size(); ++i){
            if(citations[i] >= (n - i)){
                ans = n - i;
                break;
            }
        }

        return ans;
    }
};
