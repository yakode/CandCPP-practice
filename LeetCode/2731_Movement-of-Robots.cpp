class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        long long ans = 0;
        int m = 1e9 + 7;
        
        for(int i = 0; i < nums.size(); ++i){
            if(s[i] == 'R'){
                nums[i] += d;
            }else{
                nums[i] -= d;
            }
        }

        sort(nums.begin(), nums.end());

        // 1 2 (3 4) 5 6
        // d(3, 4) * (3 * 3)
        for(int i = 1; i < nums.size(); ++i){
            long long tmp = llabs((long long)nums[i] - nums[i-1]) % m;
            ans += (tmp % m) * ((i * (nums.size() - i)) % m);
            ans %= m;
        }
        
        return ans;
    }
};
