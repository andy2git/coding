class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty()) throw runtime_error("empty input");
        
        stack<int> st;
        string s;
        int x, y;
        
        for(int i = 0; i < tokens.size(); i++){
            s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                // expect two operands
                if(st.empty()) throw runtime_error("wrong input!");
                x = st.top();
                st.pop();
                
                // expect two operands
                if(st.empty()) throw runtime_error("wrong input!");
                y = st.top();
                st.pop();
                
                if(s == "+") st.push(y+x);
                if(s == "-") st.push(y-x);
                if(s == "*") st.push(y*x);
                if(s == "/") st.push(y/x);
            }else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
