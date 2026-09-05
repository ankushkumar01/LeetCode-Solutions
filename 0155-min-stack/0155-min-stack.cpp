class MinStack {
public:
    stack<int> st;
    stack<int> helper;
    MinStack() {
        
    }
    
    void push(int value) {
        if (st.empty()) {
            st.push(value);
            helper.push(value);
        }
        else if (!st.empty() && value<= helper.top()) {
            st.push(value);
            helper.push(value);
        }
        else if (!st.empty() && value >helper.top()){
            helper.push(helper.top());
            st.push(value);
        }
    }
    
    void pop() {
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */