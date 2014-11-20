class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    void push(int x) {
        if(min_st.empty() || x <= min_st.top()) min_st.push(x);
        st.push(x);
    }

    void pop() {
        if(st.empty()) return;
        
        if(st.top() == min_st.top()) min_st.pop();
        st.pop();
    }

    int top() {
        if(!st.empty()) return st.top();
    }

    int getMin() {
        if(!min_st.empty()) return min_st.top();
    }
};
