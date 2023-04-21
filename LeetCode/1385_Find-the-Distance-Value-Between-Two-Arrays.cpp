class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        sort(arr2.begin(), arr2.end());
        for(int i = 0; i < arr1.size(); ++i){
            int l = 0, r = arr2.size(), m;
            int lb = arr1[i] - d, ub = arr1[i] + d;
            
	    ans++;
            while(l < r){
                m = l + (r-l)/2;
                if(arr2[m] < lb) l = m+1;
                else if(arr2[m] > ub) r = m;
                else{
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
}
