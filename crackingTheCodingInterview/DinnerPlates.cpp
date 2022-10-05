//https://leetcode.com/problems/dinner-plate-stacks/submissions/
class DinnerPlates {
public:
    set<int> availableStacks;
    vector<stack<int>> allStacks;
    int cap = 0;
    DinnerPlates(int capacity) 
    { 
        cap = capacity; 
    }
    
    void push(int val) 
    {
        //if there's not a stack with availability, create one
        //find the first stack with availability and add the entry
        //if that stack is now full, remove it from availableStacks
        if (availableStacks.empty()) 
        {
            allStacks.push_back(stack<int>());
            availableStacks.insert(allStacks.size() - 1);
        }
        auto idx = *availableStacks.begin();
        allStacks[idx].push(val);
        if (allStacks[idx].size() == cap) 
        {
            availableStacks.erase(availableStacks.begin());
        }
    }
    
    int pop() 
    {
        //check if there are no stacks
        //get the last stack and get its top, remove it, and remove the stack if it's empty
        //along with any other stacks now at the end that are empty
        //if the new back has availability, add it to the back of the available stacks
        
        if (allStacks.empty()) 
        {
            return -1;
        }

        auto res = allStacks.back().top(); 
        allStacks.back().pop();
        while (!allStacks.empty() && allStacks.back().empty()) 
        {
            availableStacks.erase(allStacks.size() - 1);
            allStacks.pop_back();
        }
        
        if (!allStacks.empty() && allStacks.back().size() < cap)
        {
            availableStacks.insert(allStacks.size() - 1);
        }
        return res;
    }
    
    int popAtStack(int index) 
    {
        //check for edge cases, if it's the last, pop the last
        //otherwise pop from the index and ensure that the popped
        //stack is in the available stacks
        if (allStacks.size() <= index || allStacks[index].empty())
        {
            return -1;
        }
      
        if (allStacks.size() - 1 == index) 
        {
            return pop();
        }
        
        int res = allStacks[index].top(); 
        allStacks[index].pop();
        availableStacks.insert(index);
        return res;
    }
    
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */