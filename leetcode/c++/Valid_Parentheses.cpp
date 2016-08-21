class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            // make it a function to isOpen(x)
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                
                char t = st.top();
                st.pop();
                // TODO: make it a function called isMatch(x, y)
                if(s[i] == ']' && t != '[') return false;
                if(s[i] == ')' && t != '(') return false;
                if(s[i] == '}' && t != '{') return false;
            }
        }
        
        return st.empty();
    }
};
