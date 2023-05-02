class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 1;
        int cur = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != cur){
                cur = nums[i];
                nums[ptr++] = nums[i];
            }
        }

        return ptr;
    }
};
