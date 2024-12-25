class Solution{
public:
    int jump(vector<int> &nums){
        vector<int> nr(nums.size(), INT_MAX);
        nr[nums.size() - 1] = 0;

        for(int i = nums.size() - 2; i >= 0; --i){
            for(int j = 1; j <= nums[i] && (i + j) < nums.size(); ++j){
                if(nr[i + j] != INT_MAX && nr[i] > nr[i + j] + 1)
                    nr[i] = nr[i + j] + 1;
            }
        }

        return nr[0];
    }
};
