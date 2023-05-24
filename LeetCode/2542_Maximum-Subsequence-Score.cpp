class Solution{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k){
        long long ans = 0;

        // sort nums1 and nums2 based on nums2
        vector<int> it(nums1.size());
        iota(it.begin(), it.end(), 0);
        sort(it.begin(), it.end(), [&](int &a, int &b){
            return nums2[a] > nums2[b];
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        // the greatest k numbers in [0, i]
        long long tmp = 0;

        for(int i = 0; i < k; ++i){
            pq.push(nums1[it[i]]);
            tmp += nums1[it[i]];
        }
        ans = tmp * nums2[it[k-1]];

        for(int i = k; i < nums1.size(); ++i){
            tmp -= pq.top();
            ans = max(ans, (long long)(tmp + nums1[it[i]]) * nums2[it[i]]);

            // update tmp
            if(nums1[it[i]] > pq.top()){
                pq.pop();
                pq.push(nums1[it[i]]);
                tmp += nums1[it[i]];
            }else{
                tmp += pq.top();
            }
        }

        return ans;
    }
};
