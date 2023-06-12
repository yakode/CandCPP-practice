class Solution{
public:
    vector<string> summaryRanges(vector<int> &nums){
        vector<string> ans;
        if(nums.size() == 0) return ans;

        sort(nums.begin(), nums.end());

        int left = 0, right = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[right] + 1){
                string tmp = "";
                if(left == right){
                    ans.push_back(to_string(nums[right]));
                }else{
                    ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                }
                left = i;
            }
            right = i;
        }
        if(left == right){
            ans.push_back(to_string(nums[right]));
        }else{
            ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
        }

        return ans;
    }
};
