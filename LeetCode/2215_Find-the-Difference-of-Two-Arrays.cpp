class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        const unsigned int range = 1000;
        bool ht1[range * 2 + 1] = {0}, ht2[range * 2 + 1] = {0};
        vector<vector<int>> ans;

        for(int i = 0; i < nums1.size(); ++i)
            ht1[nums1[i] + range] = true;
        for(int i = 0; i < nums2.size(); ++i)
            ht2[nums2[i] + range] = true;

        vector<int> tmp;
        for(int i = 0; i < nums1.size(); ++i){
            if(!ht2[nums1[i] + range]){
                tmp.push_back(nums1[i]);
                ht2[nums1[i] + range] = true;
            }
        }
        ans.push_back(tmp);
        tmp.clear();
        for(int i = 0; i < nums2.size(); ++i){
            if(!ht1[nums2[i] + range]){
                tmp.push_back(nums2[i]);
                ht1[nums2[i] + range] = true;
            }
        }
        ans.push_back(tmp);

        return ans;
    }
};
