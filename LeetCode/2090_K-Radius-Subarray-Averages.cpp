class Solution{
public:
    vector<int> getAverages(vector<int> &nums, int k){
        if(nums.size() < (k * 2 + 1)) return vector<int>(nums.size(), -1);
        if(k == 0) return nums;

        vector<int> ans(nums.size(), -1);
        long long int tmp = 0;
        int div = k * 2 + 1;

        for(int i = 0; i < k * 2 + 1; ++i){
            tmp += nums[i];
        }
        ans[k] = tmp / div;

        for(int i = k * 2 + 1; i < nums.size(); ++i){
            tmp -= nums[i - (k * 2 + 1)];
            tmp += nums[i];
            ans[i - k] = tmp / div;
        }

        return ans;
    }
};
