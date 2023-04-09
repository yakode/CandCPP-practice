class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x % 10 == 0 && x != 0) return false;
        
	int y = 0;
        while(y < x){
            y = y*10 + x % 10;
            x /= 10;
        }
        
	if(x == y || y/10 == x) return true;
        return false;
    }
};
