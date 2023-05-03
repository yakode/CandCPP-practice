class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size(), middle;

        // Since it is strictly increasing, finding the decreasing pattern means finding the minimum value.
        // target: find decreasing pattern↘
        while(left < right){
            middle = left + (right - left) / 2;

            // 3 4 0 1 2
            // ↗↘middle↗
            if(middle == 0 || nums[middle] < nums[middle-1]) return nums[middle];

            // 2 3 4 0 1
            // left↗middle↗↘right
            // 4 0 1 2 3
            // left↗↘middle↗right
            // 0 1 2 3 4
            // left↗middle↗right --> sorted
            if(nums[middle] > nums[right-1]) left = middle + 1;
            else if(nums[left] > nums[middle]) right = middle;
            else return nums[left];
        }

        return -1;
    }
};
