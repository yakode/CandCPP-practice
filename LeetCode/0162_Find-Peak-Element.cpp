class Solution{
public:
    int findPeakElement(vector<int> &nums){
        int left = 0, right = nums.size(), mid;
        nums.push_back(INT_MIN);

        while(left < right){
            mid = left + (right - left) / 2;

            if(nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return left;
    }
};
