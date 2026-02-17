class MinStack {
public:
 stack<long long>st;
        long long mini;
    MinStack() {
   
    }
    
    void push(int val) {
        // first element ko push kr rhe
        if(st.empty()){
            st.push(val);
            mini= val;
        }
        else
        {
            if(val<mini){
                st.push(2LL*val-mini);
                 mini =val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    
    void pop() {
        // if(st.empty()){
        //     return ;
        // }
        // else{
        //     int curr=st.top();
        //     if(curr>mini) return curr;
        //     else{
        //         int prev=mini
        //         int val=2*val-mini;
        //         mini=val;
        //         return prev;
        //     }
        // }
        if (st.empty())
            return;

        long long curr = st.top();
        st.pop();

        if (curr < mini) {
            // encoded value detected
            mini = 2 * mini - curr;
        }
        
    }
    
    int top() {
        if(st.empty()) return -1;
        long long curr= st.top();
        if(curr<mini) return mini;
        else return curr;
        
    }
    
    int getMin() {
        if(st.empty()) return -1 ;
        else return mini;
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