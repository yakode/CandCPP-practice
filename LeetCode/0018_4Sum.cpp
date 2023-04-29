// two pointer O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        if(nums.size() < 4) return ans;

        sort(nums.begin(), nums.end());

        for(int a = 0; a < nums.size()-3; ++a){
            for(int b = a+1; b < nums.size()-2; ++b){
                long long int target2 = (long long)target - nums[a] - nums[b];
                int c = b+1, d = nums.size()-1;

                while(c < d){
                    int cdsum = nums[c] + nums[d];

                    if(cdsum < target2) c++;
                    else if(cdsum > target2) d--;
                    else{
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});

                        while(c < d && nums[c] == nums[c+1]) c++;
                        while(c < d && nums[d] == nums[d-1]) d--;
                        c++;
                        d--;
                    }
                }

                while(b < nums.size()-2 && nums[b] == nums[b+1]) b++;
            }
            while(a < nums.size()-3 && nums[a] == nums[a+1]) a++;
        }

        return ans;
    }
};

// binary search O(n^3*logn)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        if(nums.size() < 4) return ans;

        sort(nums.begin(), nums.end());

        for(int a = 0; a < nums.size()-3; ++a){
            for(int b = a+1; b < nums.size()-2; ++b){
                for(int c = b+1; c < nums.size()-1; ++c){
                    long long int target2 = (long long)target - ((long long)nums[a] + nums[b] + nums[c]);

                    int l = c+1, r = nums.size(), m;
                    while(l < r){
                        m = l + (r-l) / 2;
                        if(nums[m] == target2) break;
                        else if(nums[m] < target2) l = m + 1;
                        else r = m;
                    }

                    if(nums[m] == target2){
                        if(ans.empty() ||
                            ans[ans.size()-1][0] < nums[a] ||
                            (ans[ans.size()-1][0] == nums[a] && ans[ans.size()-1][1] < nums[b]) ||
                            (ans[ans.size()-1][0] == nums[a] && ans[ans.size()-1][1] == nums[b] && ans[ans.size()-1][2] < nums[c]) ||
                            (ans[ans.size()-1][0] == nums[a] && ans[ans.size()-1][1] == nums[b] && ans[ans.size()-1][2] == nums[c] && ans[ans.size()-1][3] < nums[m]))
                            ans.push_back({nums[a], nums[b], nums[c], nums[m]});
                    }
                }
            }
        }

        return ans;
    }
};
