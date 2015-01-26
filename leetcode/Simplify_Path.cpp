class Solution {
public:
    string simplifyPath(string path) {
        if(path == "") return path;
        
        vector<string> dirs;
        int i = 0;
        int j;
        int n = path.size();
        string t;
        
        while(i < n){
            j = i+1;
            while(j < n && path[j] != '/') j++;
            t = path.substr(i, j-i);
            
            if(t == "/" || t == "/."){
            }else if(t == "/.."){
                if(!dirs.empty()) dirs.pop_back();
            }else{
                dirs.push_back(t);
            }
            i = j;
        }
        
        if(dirs.empty()) return string("/");
        
        stringstream result;
        for(auto dir : dirs){
            result << dir;
        }
        return result.str();
    }
};
