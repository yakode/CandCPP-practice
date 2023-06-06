// two pointers
class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums){
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j < k && nums[j-1] == nums[j]) j++;
                    k--;
                    while(j < k && nums[k+1] == nums[k]) k--;
                }
            }
        }
        
        return ans;
    }
};

// binary search
class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums){
        vector<vector<int>> ans;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < N; ++i){
            for(int j = i+1; j < N; ++j){
                if(ans.size() !=0 && ans[ans.size()-1][0] == nums[i] && ans[ans.size()-1][1] >= nums[j])
                    continue;
                // binary search (nums[i]+nums[j]) * -1
                int l = j+1, r = N, m;
                int target = -1 * (nums[i]+nums[j]);
                if(target > 100000 || target < -100000) continue;
                while(l < r){
                    m = (l+r) / 2;
                    if(nums[m] < target) l = m+1;
                    else if(nums[m] > target) r = m;
                    else{
                        ans.push_back({nums[i], nums[j], nums[m]});
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
