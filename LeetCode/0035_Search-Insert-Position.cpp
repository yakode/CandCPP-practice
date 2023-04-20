class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), m;

        while(l < r){
            m = (l+r) / 2;
            if(nums[m] < target) l = m + 1;
            else if(nums[m] > target) r = m;
            else return m;
        }
        
        m = (l+r) / 2;
        return m ;
    }
};
