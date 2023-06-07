class Solution{
public:
    int minFlips(int a, int b, int c){
        int ans = 0;
        int ab = a | b;
        int xorc = ab ^ c;

        while(xorc > 0){
            if(xorc % 2 == 1){
                if(ab % 2 == 1){
                    ans += (a % 2) + (b % 2);
                }else{
                    ans++;
                }
            }
            xorc >>= 1;
            ab >>= 1;
            a >>= 1;
            b >>= 1;
        }

        return ans;
    }
};
