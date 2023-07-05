class Solution{
public:
    int longestSubarray(vector<int> &nums){
        int ans = 0;
        int left = 0, last0 = -1;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                left = last0 + 1;
                last0 = i;
            }else{
                if(last0 < 0) ans = max(ans, i - left + 1);
                else ans = max(ans, i - left);
            }
        }

        if(last0 == -1 && ans > 0) return ans - 1;
        return ans;
    }
};
