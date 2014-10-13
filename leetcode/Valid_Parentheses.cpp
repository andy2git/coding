class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;
        if(s.size() == 1) return false;
        
        stack<char> st;
        char t;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                t = st.top();
                st.pop();
                if(s[i] == ')'){
                    if(t != '(') return false;
                }else if(s[i] == '}'){
                    if(t != '{') return false;
                }else if(s[i] == ']'){
                    if(t != '[') return false;
                }
            }
        }
        
        if(st.empty()) return true;
        else return false;
    }
};
