class Solution{
public:
    int findChampion(int n, vector<vector<int>> &edges){
        bool *weaker = (bool*) malloc(n * sizeof(bool));
        for(int i = 0; i < n; ++i) weaker[i] = false;
        int nr = n;

        for(auto &e: edges){
            if(weaker[e[1]] == false){
                nr--;
                weaker[e[1]] = true;
            }
        }

        if(nr != 1)
            return -1;
        for(int i = 0; i < n; ++i)
            if(!weaker[i])
                return i;
        return -1;
    }
};
