class MyQueue {
public:
    stack<int>ft;
    stack<int>st;
    int pop_element;
    int repop;
    int len;
    MyQueue() {
        len=0;
    }
    
    void push(int x) {
        ft.push(x);
        len++;
    }
    
    int pop() {
        if (ft.empty()) return -1;
        while(!ft.empty()){
            pop_element=ft.top();
            ft.pop();
            st.push(pop_element);
        }
        repop=st.top();
        st.pop();
        len--;
        while(!st.empty()){
            pop_element=st.top();
            st.pop();
            ft.push(pop_element);
        }
        return repop;
    }
    
    int peek() {
        if (ft.empty()) return -1;
        while(!ft.empty()){
            pop_element=ft.top();
            ft.pop();
            st.push(pop_element);
        }
        repop=st.top();
        while(!st.empty()){
            pop_element=st.top();
            st.pop();
            ft.push(pop_element);
        }
        return repop;
    }
    
    bool empty() {
        if (len==0) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */