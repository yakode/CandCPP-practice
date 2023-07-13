class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
        vector<vector<int>> related(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        int done = 0;

        for(auto &item: prerequisites){
            ++degree[item[0]];
            related[item[1]].push_back(item[0]);
        }

        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 0; i < numCourses; ++i){
                if(degree[i] == 0){
                    flag = true;
                    ++done;
                    degree[i] = -1;
                    for(int j = 0; j < related[i].size(); ++j)
                        --degree[related[i][j]];
                }
            }
        }

        if(done == numCourses)
            return true;
        return false;
    }
};
