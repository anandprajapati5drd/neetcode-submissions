class MinStack {
public:
    std::stack<int> st;
    std::stack<int> minStack;
    int mini = INT_MAX;
    MinStack() {}
    
    void push(int val) {
        st.push(val);

        if(minStack.empty() || val <= minStack.top()){
        minStack.push(val);
        }
    }
    
    void pop() {
        if(!st.empty()){
            if(st.top() == minStack.top()){
                minStack.pop();
            }
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }
    
    int getMin() {
        return minStack.top();
    }
};
