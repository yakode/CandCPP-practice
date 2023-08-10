class Solution{
public:
    bool search(vector<int> &nums, int target){
        int left = 0, right = nums.size(), middle;

        while(left < right){
            middle = left + (right - left) / 2;

            if(nums[middle] == target || nums[left] == target){
                return true;
            }else if(nums[left] == nums[right - 1]){
                ++left;
                --right;
            }else if(((nums[right - 1] < target || target < nums[middle]) && nums[middle] <= nums[right - 1]) || (target >= nums[left] && target < nums[middle] && nums[middle] > nums[left])){
                right = middle;
            }else{
                left = middle + 1;
            }
        }

        return false;
    }
};
