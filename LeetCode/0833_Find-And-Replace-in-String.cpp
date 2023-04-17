// record the replacement that should be done before do any replacement
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        bool checked[1005] = {0};
        int map[1005] = {0};

        // record the original position
        for(int i = 0; i < indices.size(); ++i){
            map[indices[i]] = i;
        }

        // sort the indices to make replace easier
        sort(indices.begin(), indices.end());

        // Check if the substring sources[map[indices[i]]] 
		// occurs at index indices[i] in the original string s.
        for(int i = 0; i < indices.size(); ++i){
            string tmp = s.substr(indices[i], sources[map[indices[i]]].size());
            if(tmp == sources[map[indices[i]]]) checked[i] = true;
        }

        int i, j;
        string ans = "";
        
        // do the replacement
        for(i = 0, j = 0; i < s.size() && j < indices.size(); ++i){
            if(i == indices[j] && checked[j] == true){
                ans += targets[map[indices[j]]];
                i += (sources[map[indices[j]]].size()-1);
                ++j;
            }else{
                if(i == indices[j] && checked[j] == false) ++j;
                ans += s[i];
            }
            
        }
        if(i < s.size()) ans += s.substr(i, (s.size()-i));

        return ans;
    }
};

// do the replacement from back to front
// then it would not change the index of the substring that had not be checked
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int map[1005] = {0};

        // record the original position
        for(int i = 0; i < indices.size(); ++i){
            map[indices[i]] = i;
        }

        // sort the indices (decreasing) to make replace easier
        sort(indices.rbegin(), indices.rend());

        for(int i = 0; i < indices.size(); ++i){
            string source = sources[map[indices[i]]];
            string target = targets[map[indices[i]]];
            string tmp = s.substr(indices[i], source.size());
            if(tmp == source){
                s = s.substr(0, indices[i]) + target + s.substr(indices[i]+source.size());
                cout << s << '\n';
            }
        }

        return s;
    }
};
