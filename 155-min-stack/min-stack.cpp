class MinStack {
private:
    stack<int> minSt;
    stack<int> st;
public:
    MinStack() {
        while (!st.empty()) st.pop();
        while (!minSt.empty()) minSt.pop();
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;
        int val = st.top();
        st.pop();
        if (val == minSt.top()) minSt.pop();
    }
    
    int top() {
        if (st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */