class Solution{
public:
    void rotate(vector<int> &nums, int k){
        int n = nums.size();
        k %= n;
        if(k == n)
            return;

        int left = 0, right = n - k - 1;
        while(left < right){
            swap(nums[left++], nums[right--]);
        }
        left = n - k, right = n - 1;
        while(left < right){
            swap(nums[left++], nums[right--]);
        }
        left = 0, right = n - 1;
        while(left < right){
            swap(nums[left++], nums[right--]);
        }
    }
};
