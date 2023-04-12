class Solution {
public:
    string simplifyPath(string path) {
        stack<string> buf;
        string tmp;
        int len = path.size();
        for(int i = 0; i < len; ++i){
            if(path[i] == '/'){
                continue;
            }
            else{
                int j = i+1;
                while(j < len && path[j] != '/') ++j;
                tmp = path.substr(i, (j-i));
                if(tmp == ".."){
                    if(!buf.empty()) buf.pop();
                }else if(tmp != "."){
                    buf.push(tmp);
                }
                i = j;
            }
        }
        tmp = "";
        while(!buf.empty()){
            tmp = "/" + buf.top() + tmp;
            buf.pop();
        }
        if(tmp == "") return "/";
        return tmp;
    }
};
