class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int middle = (len1 + len2) /2 + 1;
        int ptr1 = 0, ptr2 = 0;
        int cnt = 0, prev = -1;
        while(ptr1 < len1 && ptr2 < len2){
            cnt++;
            if(nums1[ptr1] < nums2[ptr2]){
                ptr1++;
                if(cnt == middle){
                    if((len1+len2) %2 == 0){
                        if(prev == 2) return (double)(nums2[ptr2-1]+nums1[ptr1-1]) / 2;
                        else return (double)(nums1[ptr1-2]+nums1[ptr1-1]) / 2;
                    }else{
                        return nums1[ptr1-1];
                    }
                }
                prev = 1;
            }else{
                ptr2++;
                if(cnt == middle){
                    if((len1+len2) %2 == 0){
                        if(prev == 1) return (double)(nums2[ptr2-1]+nums1[ptr1-1]) / 2;
                        else return (double)(nums2[ptr2-2]+nums2[ptr2-1]) / 2;
                    }else{
                        return nums2[ptr2-1];
                    }
                }
                prev = 2;
            }
        }
        if(ptr1 < len1){
            if((len1+len2) %2 == 0){
                if(middle - cnt > 1) return (double)(nums1[ptr1+(middle-cnt)-2]+nums1[ptr1+(middle-cnt)-1]) / 2;
                if(prev == 2) return (double)(nums2[ptr2-1]+nums1[ptr1]) / 2;
                else return (double)(nums1[ptr1-1]+nums1[ptr1]) / 2;
            }else{
                return nums1[ptr1+(middle-cnt)-1];
            }
        }else{
            if((len1+len2) %2 == 0){
                if(middle - cnt > 1) return (double)(nums2[ptr2+(middle-cnt)-2]+nums2[ptr2+(middle-cnt)-1]) / 2;
                if(prev == 1) return (double)(nums1[ptr1-1]+nums2[ptr2]) / 2;
                else return (double)(nums2[ptr2-1]+nums2[ptr2]) / 2;
            }else{
                return nums2[ptr2+(middle-cnt)-1];
            }
        }
        return 0;
    }
};
