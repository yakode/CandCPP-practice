class Solution {
public:
    string convert(string s, int numRows) {
        // no zigzag :)
        if(numRows == 1) return s;
        
        string ans = "";
        int len = s.size();

        /*
            00        08        16 (+8)
            01     07 09     15 17 (+6 +2 +6 ...)
            02   06   10   14   18 (+4 +4 +4 ...)
            03 05     11 13     19 (+2 +6 +2 ...)
            04        12        20 (+8)

            numRows = 5
            8 = 2*(numRows-1)
        */

        // first row
        int interval = 2*(numRows-1);
        for(int j = 0; j < len; j += interval){
            ans += s[j];
        }
        // middle rows
        for(int i = 1; i < numRows-1; ++i){
            int j = i;
            interval = 2*(numRows-1-i);
            while(j < len){
                ans += s[j];
                j += interval;
                interval = 2*(numRows-1)-interval;
            }
        }
        // last row
        interval = 2*(numRows-1);
        for(int j = numRows-1; j < len; j += interval){
            ans += s[j];
        }

        return ans;
    }
};
