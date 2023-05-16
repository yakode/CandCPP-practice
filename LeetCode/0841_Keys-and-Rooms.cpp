class Solution{
public:
    bool checked[1005]= {0};

    void dfs(int i, vector<vector<int>>& rooms){
        if(checked[i]) return;

        checked[i] = true;

        for(int j = 0; j < rooms[i].size(); ++j)
            dfs(rooms[i][j], rooms);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms){
        dfs(0, rooms);

        for(int i = 0; i < rooms.size(); ++i)
            if(!checked[i]) return false;

        return true;
    }
};
