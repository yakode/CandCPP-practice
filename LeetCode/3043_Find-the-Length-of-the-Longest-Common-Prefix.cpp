class Solution{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2){
        int ans = 0;
        set<int> hash;

        for(auto &i: arr1){
            while(i){
                hash.insert(i);
                i /= 10;
            }
        }

        for(auto &i: arr2){
            while(i){
                if(hash.count(i)){
                    if(to_string(i).size() > ans){
                        ans = to_string(i).size();
                    }
                    break;
                }
                i /= 10;
            }
        }

        return ans;
    }
};
