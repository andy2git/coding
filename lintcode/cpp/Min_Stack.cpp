class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;   
public:
    MinStack() {}

    void push(int number) {
        dataStack.push(number);
        if(minStack.empty() || number <= minStack.top()){
            minStack.push(number);
        }
    }


    int pop() {
        int x = dataStack.top();
        dataStack.pop();
        
        if(x == minStack.top()){
            minStack.pop();
        }
        return x;
    }


    int min() {
        return minStack.top();
    }
};
