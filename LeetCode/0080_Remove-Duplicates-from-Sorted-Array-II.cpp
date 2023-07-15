class Solution{
public:
    int removeDuplicates(vector<int> &nums){
        int i = 0;

        for(int j = 0; j < nums.size(); ++j){
            while(j < nums.size() && i > 1 && nums[j] == nums[i - 1] && nums[j] == nums[i - 2])
                ++j;
            if(j < nums.size())
                nums[i++] = nums[j];
        }

        return i;
    }
};
