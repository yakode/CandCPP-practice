class Solution{
    int quick(vector<int> &nums, int left, int right){
        int pivot = nums[left], i = left;
        ++left;
        
        while(left <= right){
            if(nums[left] < pivot && nums[right] > pivot){
                swap(nums[left++], nums[right--]);
            }else{
                if(nums[left] >= pivot)
                    ++left;
                if(nums[right] <= pivot)
                    --right;
            }
        }

        swap(nums[i], nums[right]);

        return right;
    }

public:
    int findKthLargest(vector<int> &nums, int k){
        int left = 0, right = nums.size() - 1;

        while(true){
            int ret = quick(nums, left, right);
            if(ret == k - 1)
                return nums[ret];
            if(ret > k - 1)
                right = ret - 1;
            else
                left = ret + 1;
        }

        return -1;
    }
};
