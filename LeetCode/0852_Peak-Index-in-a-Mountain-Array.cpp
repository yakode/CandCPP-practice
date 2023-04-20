class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size()-1, m;

        while(l < r){
            m = (l+r) / 2;
            if(arr[m] < arr[m+1]) l = m+1;
            else r = m;
        }

        return l;
    }
};
