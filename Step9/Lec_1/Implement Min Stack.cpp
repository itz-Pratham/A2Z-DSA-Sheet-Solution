class MinStack {
    public:
        stack<pair<int,int>> st;
        int msf = INT_MAX;
        int t=-1;
        MinStack() {}
        
        void push(int val) {
            if(st.empty()) msf = INT_MAX;
            if(val < msf){
                msf = val;
            }
            st.push(make_pair(val,msf));
        }
        
        void pop() {
            st.pop();
            if(!st.empty())
                msf = st.top().second;
            else
                msf = INT_MAX;
        }
        
        int top() {
            return st.top().first;
        }
        
        int getMin() {
            return st.top().second;
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