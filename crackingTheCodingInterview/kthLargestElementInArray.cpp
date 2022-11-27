//https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		//O(n)
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < nums.size(); i++)
        {
            heap.push(nums[i]);
            if(heap.size() > k)
            {
                heap.pop();
            }
        }

        return heap.top();
    }
};