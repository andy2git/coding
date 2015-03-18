/* '/' is included in the path */
class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty()) return "";
        
        vector<string> st;
        int i = 0;
        int n = path.size();
        
        while(i < n){
            string t = nextToken(path, i);
            
            if(t == "/" || t == "/."){
                continue;
            }else if(t == "/.."){
                if(!st.empty()) st.pop_back();
            }else{
                st.push_back(t);
            }
        }
        
        if(st.empty()) return "/";
        
        stringstream ss;
        for(auto x: st){
            ss << x;
        }
        
        return ss.str();
    }
private:
    string nextToken(string &st, int &i){
        int n = st.size();
        int j = i+1;
        while(j < n && st[j] != '/') j++;
        
        string result;
        if(i < n) result = st.substr(i, j-i);
        i = j;
        
        return result;
    }
};
