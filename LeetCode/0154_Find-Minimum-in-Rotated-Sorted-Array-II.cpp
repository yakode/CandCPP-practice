class Solution{
private:
    bool existed[10001] = {0};
public:
    int findMin(vector<int> &nums){
        vector<int> nums2;
        for(int i = 0; i < nums.size(); ++i){
            if(!existed[nums[i] + 5000]){
                nums2.push_back(nums[i]);
                existed[nums[i] + 5000] = true;
            }
        }

        int left = 0, right = nums2.size(), mid;
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(mid == 0 || nums2[mid] < nums2[mid - 1]) return nums2[mid];

            if(nums2[mid] > nums2[nums2.size() - 1]) left = mid + 1;
            else right = mid;
        }

        return -1;
    }
};
