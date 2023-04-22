class Solution {
public:
    int mySqrt(int x) {
        long int l = 0, r = (long)x+1, m;

        while(l < r){
            m = l + (r-l)/2;
            if(m*m == x) return m;
            if(m * m > x) r = m;
            else l = m+1;
        }
        
        return l-1;
    }
};
