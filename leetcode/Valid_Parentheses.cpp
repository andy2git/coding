class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                
                char t = st.top();
                st.pop();
                
                if(s[i] == ']' && t != '[') return false;
                if(s[i] == ')' && t != '(') return false;
                if(s[i] == '}' && t != '{') return false;
            }
        }
        
        if(st.empty()) return true;
        else return false;
    }
};
