class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.size() == 0) throw runtime_error("empty input!");
        
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
                opExec(st, tokens[i]);        
            }else{
                st.push(stoi(tokens[i]));
            }
        }

        if(st.empty()) throw runtime_error("wrong expr!");
        else return st.top();
    }
private:
    void opExec(stack<int> &st, string &op){
        int a, b;
        if(st.empty()) throw runtime_error("wrong expr");
        a = st.top();
        st.pop();
                
        if(st.empty()) throw runtime_error("wrong expr");
        b = st.top();
        st.pop();
    
        if(op == "+") st.push(b+a);
        if(op == "-") st.push(b-a);
        if(op == "/") st.push(b/a);
        if(op == "*") st.push(b*a);
    }
};
