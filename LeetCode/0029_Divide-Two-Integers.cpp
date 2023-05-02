// binary long division
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool minus = false;
        if(dividend < 0) minus ^= true;
        if(divisor < 0) minus ^= true;

        long ans = 0;
        unsigned _dividend = labs(dividend), _divisor = labs(divisor);

        unsigned mask = _divisor;
        unsigned base = 1;
        for(unsigned i = _divisor, j = _dividend; j > 0; i >>= 1, j >>= 1){
            if(i <= 0){
                base <<= 1;
                mask <<= 1;
            }
        }

        while(mask >= _divisor){
            if(_dividend >= mask){
                _dividend -= mask;
                ans += base;
            }
            mask >>= 1;
            base >>= 1;
        }

        if(minus) return ans * -1 < -2147483648? -2147483648: ans * -1;;
        return ans > 2147483647? 2147483647: ans;
    }
};
