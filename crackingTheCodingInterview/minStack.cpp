//https://leetcode.com/problems/min-stack/
class MinStack {
    //because only the top element gets removed, having a min stack alongside it works
	//each item of the min stack is the minimum of that stack down
     stack<int> plainStack, minStack;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        plainStack.push(val);
        
        if (!minStack.empty())
            val = min(val, minStack.top());
        
        minStack.push(val);
    }
    
    void pop() {
        minStack.pop();
        plainStack.pop();
    }
    
    int top() {
        return plainStack.top();
    }
    
    int getMin() {
        return minStack.top();
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