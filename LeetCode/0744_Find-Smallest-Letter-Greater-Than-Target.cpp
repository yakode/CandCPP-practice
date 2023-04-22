class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[letters.size()-1] <= target || letters[0] > target) return letters[0];

        int l = 0, r = letters.size(), m;
        target += 1;

        while(l < r){
            m = l + (r-l)/2;
            if(letters[m] == target) break;
            else if(letters[m] < target) l = m+1;
            else r = m;
        }

        m = l + (r-l)/2;
        return letters[m];
    }
};
