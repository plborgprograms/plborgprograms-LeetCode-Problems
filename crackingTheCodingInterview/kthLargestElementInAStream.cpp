//https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/
class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>> heap;

    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int x = 0; x < nums.size(); x++)
        {
            add(nums[x]);
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size() > size)
        {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */