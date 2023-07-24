class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == -1)
            return 1 / x;
        if(n == 1)
            return x;
        
        double half = myPow(x, n / 2);
        half *= half;
        if(n % 2) half *= (n > 0)? x: 1 / x;
        return half;
    }
};
