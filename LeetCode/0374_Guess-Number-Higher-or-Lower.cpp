/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, m;

        while(l <= r){
            m = l/2 + r/2 + (l%2 == 1 && r%2 == 1);
            int ret = guess(m);
            if(ret == -1) r = m-1;
            else if(ret == 1) l = m+1;
            else return m;
        }

        return -1;
    }
};
