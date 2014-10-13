class Solution {
public:
    string simplifyPath(string path) {
        if(path == "") return path;
        
        stack<string> st;
        int n = path.size()-1;
        int i = 0;
        int j;
        string t;
        
        while(i <= n){
            j = i+1;
            
            while(j <= n && path[j] != '/') j++;
            
            t = path.substr(i, j-i);
            if(t == "/" || t == "/."){
            }else if(t == "/.."){
                if(!st.empty()) st.pop();
            }else{
                st.push(t);
            }
            i = j;
        }
        
        if(st.empty()) return string("/");
        
        string result;
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};
