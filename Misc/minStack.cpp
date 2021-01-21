class MinStack
{
public:
    /** initialize your data structure here. */
    vector<int> stack, minimum;
    int mini;

    MinStack()
    {
        vector<int> stack;
        mini = INT_MAX;
    }

    void push(int x)
    {
        if (stack.size() == 0)
            mini = INT_MAX;
        stack.push_back(x);
        mini = min(mini, x);
        minimum.push_back(mini);
    }

    void pop()
    {
        stack.pop_back();
        minimum.pop_back();
        if (minimum.size() != 0)
            mini = minimum.back();
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return minimum.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */