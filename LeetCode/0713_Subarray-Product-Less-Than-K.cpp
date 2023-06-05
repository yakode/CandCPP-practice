class Solution{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k){
        int ans = 0;
        long long product = 1;

        if(k == 0) return 0;

        for(int left = 0, right = 0; right < nums.size(); ++right){
            product *= nums[right];
            while(product >= k && left <= right){
                product /= nums[left++];
            }
            ans += (right - left + 1);
        }

        return ans;
    }
};
