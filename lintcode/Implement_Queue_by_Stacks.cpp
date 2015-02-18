class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        stack1.push(element);
    }
    
    int pop() {
        if(stack2.empty()) copyStack(stack1, stack2);
        
        if(!stack2.empty()){
            int x = stack2.top();
            stack2.pop();
            return x;
        }else throw runtime_error("empty queue!");
    }

    int top() {
        if(stack2.empty()) copyStack(stack1, stack2);
        
        if(!stack2.empty()) return stack2.top();
        else throw runtime_error("empty queue!");
    }
private:
    //copy elements from stack1 => stack2
    void copyStack(stack<int> &st1, stack<int> &st2){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }
};
