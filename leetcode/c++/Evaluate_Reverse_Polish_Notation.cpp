class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty()) throw runtime_error("empty input!");
        
        stack<int> st;
        for(auto t:tokens){
            if(isOperator(t)){
                int x = getTop(st);
                int y = getTop(st);
                
                if(t == "+") st.push(y+x);
                else if(t == "-") st.push(y-x);
                else if(t == "*") st.push(y*x);
                else st.push(y/x);
            }else{
                st.push(stoi(t));
            }
        }
        
        if(st.size() == 1) return st.top();
        else throw runtime_error("wrong expression!");
    }
private:
    bool isOperator(string &st){
        return (st=="+") || (st == "-") || (st == "*") || (st == "/");
    }
    
    int getTop(stack<int> &st){
        if(st.empty()) throw runtime_error("wrong input");
        int x = st.top();
        st.pop();
        
        return x;
    }
};
