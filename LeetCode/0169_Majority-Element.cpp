/*
 * sorting nums and nums[n/2] would be the majority element
 * since the majority element appears more than n/2 times
 * the miidle of nums must be the majority element
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// Moore voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ans = nums[0];
        for(int i = 0; i < nums.size(); ++i){
            if(cnt == 0) ans = nums[i];
            if(ans == nums[i]) cnt++;
            else cnt--;
        }
        return ans;
    }
};
