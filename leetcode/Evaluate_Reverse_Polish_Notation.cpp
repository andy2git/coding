class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty()) return 0;
        
        stack<int> st;
        string s;
        int x, y;
        
        for(int i = 0; i < tokens.size(); i++){
            s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                if(!st.empty()) {
                    x = st.top();
                    st.pop();
                }
                if(!st.empty()) {
                    y = st.top();
                    st.pop();
                }
                if(s == "+") st.push(y+x);
                if(s == "-") st.push(y-x);
                if(s == "*") st.push(y*x);
                if(s == "/") st.push(y/x);
            }else{
                st.push(atoi(s.c_str()));
            }
        }
        return st.top();
    }
};
