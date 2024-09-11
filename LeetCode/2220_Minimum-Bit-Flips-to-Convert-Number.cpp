class Solution{
public:
    int minBitFlips(int start, int goal){
        int x, y;
        int ans = 0;

        while(start || goal){
            x = start % 2;
            y = goal % 2;
            if(x != y) ans++;
            start /= 2;
            goal /= 2;
        }

        return ans;
    }
};
