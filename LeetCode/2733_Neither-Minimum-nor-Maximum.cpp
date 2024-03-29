class Solution{
public:
    int findNonMinOrMax(vector<int> &nums){
        int maxi = nums[0], mini = nums[0];
        
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > maxi) maxi = nums[i];
            else if(nums[i] < mini) mini = nums[i];
            else return nums[i];
        }
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != maxi && nums[i] != mini) return nums[i];
        }
        return -1;
        
    }
};

class Solution{
public:
    int findNonMinOrMax(vector<int> &nums){
        if(nums.size() < 3) return -1;

        sort(nums.begin(), nums.begin() + 3);

        return nums[1];
    }
};
