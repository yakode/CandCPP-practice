class Solution{
public:
    int search(vector<int> &nums, int target){
        int left = 0, right = nums.size(), mid;
        int last = nums[nums.size() - 1];

        while(left < right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > last){
                // mid > last
                if(target > last){
                    if(target > nums[mid]){
						// target > mid > last
                        left = mid + 1;
                    }else{
						// mid > target > last
                        right = mid;
                    }
                }else{
					// mid > last > target
                    left = mid + 1;
                }
            }else{
                // last > mid
                if(target > last){
                    // target > last > mid
                    right = mid;
                }else{
                    if(target > nums[mid]){
                        // last > target > mid
                        left = mid + 1;
                    }else{
                        // last > mid > target
                        right = mid;
                    }
                }
            }
        }

        return -1;
    }
};
