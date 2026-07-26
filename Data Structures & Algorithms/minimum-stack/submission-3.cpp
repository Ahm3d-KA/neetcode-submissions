class MinStack {
private:
    vector<int> st;
    vector<int> pre;
public:
    MinStack() {
        return;
    }
    
    void push(int val) {
        if (pre.empty()) {
            pre.push_back(val);
        }
        else {
        pre.push_back(min(pre[pre.size()-1], val));

        }
        st.push_back(val);
    }
    
    void pop() {
        pre.pop_back();

        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1];
        
    }
    
    int getMin() {
        return pre[pre.size()-1];
        
    }
};
