class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int>q1,q2;
    MyStack() {
       
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q2.empty()){
            return -1;
        }
        int front = q2.front();
        q2.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        if(!q2.empty()) return q2.front();
        return -1;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return !(q2.size() > 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
