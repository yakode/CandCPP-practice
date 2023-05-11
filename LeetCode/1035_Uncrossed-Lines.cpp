class Solution {
public:
    int dp[501][501];

    int LCS(int i, int j, vector<int>& nums1, vector<int>& nums2){
		// find the longest common subsequence

        if(i >= nums1.size() || j >= nums2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(nums1[i] == nums2[j])
            return dp[i][j] = max(LCS(i+1, j+1, nums1, nums2)+1, max(LCS(i+1, j, nums1, nums2), LCS(i, j+1, nums1, nums2)));
        return dp[i][j] = max(LCS(i+1, j, nums1, nums2), LCS(i, j+1, nums1, nums2));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));

        return LCS(0, 0, nums1, nums2);
    }
};
