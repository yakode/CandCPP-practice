class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};

        int left = 0, right = nums.size(), mid;
        while(left < right){
            mid = left + (right-left)/2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid;
            else{
                if(mid == 0 || nums[mid-1] != target){
                    ans[0] = mid;
                    break;
                }else{
                    right = mid;
                }
            }
        }

        left = 0, right = nums.size();
        while(left < right){
            mid = left + (right-left)/2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid;
            else{
                if(mid == nums.size()-1 || nums[mid+1] != target){
                    ans[1] = mid;
                    break;
                }else{
                    left = mid+1;
                }
            }
        }

        return ans;
    }
};
