class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool positive = true;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0) positive ^= 1;
            else if(nums[i] == 0) return 0;
        }

        if(positive) return 1;
        return -1;
    }
};
