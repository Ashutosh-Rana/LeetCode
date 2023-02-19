class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    int min_ele=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(val<min_ele){
            min_ele=val;
            min_st.push(val);
        }
        else{
            min_st.push(min_ele);
        }
    }
    
    void pop() {
        st.pop();
        min_st.pop();
        if(!st.empty()){
            min_ele=min_st.top();
        }
        else{
            min_ele=INT_MAX;
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
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