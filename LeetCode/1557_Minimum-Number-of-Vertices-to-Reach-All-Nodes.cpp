class Solution{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges){
        vector<int> ans;
        bool hasInEdge[200000] = {false};
        
        for(int i = 0; i < edges.size(); ++i)
            hasInEdge[edges[i][1]] = true;

        for(int i = 0; i < n; ++i)
            if(!hasInEdge[i]) ans.push_back(i);

        return ans;
    }
};
