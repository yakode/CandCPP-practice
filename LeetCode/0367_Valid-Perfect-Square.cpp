class Solution {
public:
    bool isPerfectSquare(int num) {
        long int l = 0, r = (long)num+1, m;

        while(l < r){
            m = l + (r-l)/2;
            if(m*m == num) return true;
            if(m * m > num) r = m;
            else l = m+1;
        }
        
        return false;
    }
};
