class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int p2[100000];
        p2[0] = 1;
        int mod = 1e9 + 7;

        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); ++i)
            p2[i] = (p2[i-1] << 1) % mod;

        for(int i = 0, j = nums.size()-1; i <= j; ++i){
            while(i <= j && nums[i] + nums[j] > target) j--;
            if(i > j) break;
            ans = (ans + p2[j-i]) % mod;
        }

        return ans;
    }
};
