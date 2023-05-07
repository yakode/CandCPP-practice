class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the minimum bigger number
        // eg. 12043 --> 12304

        for(int i = nums.size()-1; i > 0; --i){
            // check that I should change how many digits
            // eg. 12 043
            if(nums[i] > nums[i-1]){
                // find the minimun most significant number that bigger than previous one
                // eg. 12 340
                int mini = i;
                for(int j = i+1; j < nums.size(); ++j){
                    if(nums[j] > nums[i-1] && nums[j] < nums[mini]) mini = j;
                }
                swap(nums[i-1], nums[mini]);

                // get minimum number
                // eg. 12 304
                sort(nums.begin()+i, nums.end());

                return;
            }
        }

        sort(nums.begin(), nums.end());
    }
};
