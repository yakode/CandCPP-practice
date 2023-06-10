class Solution{
public:
    bool isFascinating(int n){
        int check = 0;
        
        int tmp = n;
        while(tmp){
            check |= (1 << tmp % 10);
            tmp /= 10;
        }

        tmp = n * 2;
        if(tmp > 999) return false;
        while(tmp){
            check |= (1 << tmp % 10);
            tmp /= 10;
        }

        tmp = n * 3;
        if(tmp > 999) return false;
        while(tmp){
            check |= (1 << tmp % 10);
            tmp /= 10;
        }

        if(check == 1022) return true;
        return false;
    }
};
