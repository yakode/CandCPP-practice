class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;

        while(i < start.size() && j < target.size()){
            while(i < start.size() && start[i] == '_')
                ++i;
            while(j < target.size() && target[j] == '_')
                ++j;

            if(i == start.size() && j == target.size())
                return true;
            else if(i == start.size() || j == target.size())
                return false;
            if(start[i] != target[j])
                return false;
            if(start[i] == 'L' && i < j)
                return false;
            else if(start[i] == 'R' && i > j)
                return false;

            ++i;
            ++j;
        }
        while(i < start.size() && start[i] == '_')
            ++i;
        while(j < target.size() && target[j] == '_')
            ++j;
        if(i != j)
            return false;

        return true;
    }
};
