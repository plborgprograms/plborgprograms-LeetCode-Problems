//https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
public:
    //Here we have a design decision, to shift code move entries in the case of pushing or peeking/popping
    //This depends on what's getting called more; you can a O(n) on each time you push by popping the whole 
    //stack each time like this one: https://leetcode.com/problems/implement-queue-using-stacks/discuss/64196/0-ms-C%2B%2B-solution-using-one-Stack-w-explanation. or this one https://leetcode.com/problems/implement-queue-using-stacks/discuss/64250/Accepted-0ms-c%2B%2B-solution-with-two-std%3A%3Astack-easy-understand. 
    //I'd rather do the heavy operation in one large batch when we're out of things to pop instead of each time I want to push
    
    
    //push to the rear stack always
    //when popping or peeking, if the front stack is empty, pop all elements into the front stack which will preserve order
    //for empty, return true if both are empty
    
     stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty())
        {
            shiftInputToOutput();
        }
        
        int result = output.top();
        output.pop();
        return result;
    }
    
    int peek() {
        if(output.empty())
        {
            shiftInputToOutput();
        }
        
        return output.top();
    }
    
    void shiftInputToOutput()
    {
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
    }
    
    bool empty() {
        return (input.empty() && output.empty());
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