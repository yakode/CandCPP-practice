class Solution{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
        int ptr = nums1.size() - 1;
        
        m--;
        n--;

        while(m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[ptr--] = nums1[m--];
            }else{
                nums1[ptr--] = nums2[n--];
            }
        }

        while(m >= 0){
            nums1[ptr--] = nums1[m--];
        }

        while(n >= 0){
            nums1[ptr--] = nums2[n--];
        }
    }
};
