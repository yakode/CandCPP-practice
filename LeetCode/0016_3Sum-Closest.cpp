class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int d = 99999;

        for(int i = 0; i < nums.size()-2; ++i){
            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return sum;
                else if(sum < target) l++;
                else r--;
                if(abs(sum-target) < abs(d)) d = sum-target;
            }
        }

        return target + d;
    }
};
