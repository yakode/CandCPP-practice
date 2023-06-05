class Solution{
public:
    int minSubArrayLen(int target, vector<int> &nums){
        int ans = nums.size() + 1;

        for(int l = 0, r = 0, cnt = 0; r < nums.size(); ++r){
            cnt += nums[r];
            while(cnt >= target){
                if((r - l + 1) < ans)
                    ans = (r - l + 1);
                cnt -= nums[l++];
            }
        }

        if(ans > nums.size()) return 0;
        return ans;
    }
};
