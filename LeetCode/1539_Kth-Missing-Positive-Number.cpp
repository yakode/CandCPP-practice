class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size(), mid;

        while(left < right){
            mid = left + (right - left) / 2;
            int d = arr[mid] - mid - 1;

            if(d < k){
                // ... arr[mid] ... ans ...
                // -d miss-|
                // -----k miss -----|

                left = mid + 1;
            }else if(d > k){
                // ... ans ... arr[mid] ...
                // -----d miss----|
                // --k miss --|

                if(mid == 0) return k;
                if(mid > 0 && d - (arr[mid] - arr[mid-1] - 1) >= k) right = mid;
                else return arr[mid] - (d - k) - 1;
            }else{
                // ... arr[mid-1] ... ans ... arr[mid] ...
                // ------------d miss------------|
                // ------------k miss------------|
                
                if(mid == 0) return k;
                if(mid > 0 && arr[mid-1] != arr[mid] - 1) return arr[mid] - (d - k) - 1;
                else right = mid;
            }
        }

        // arr ... ans
        int d = arr[arr.size()-1] - (arr.size() - 1) - 1;
        return arr[arr.size()-1] + (k - d);
    }
};
