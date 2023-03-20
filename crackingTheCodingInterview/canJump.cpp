//https://leetcode.com/problems/jump-game/submissions/
class Solution {
public:
    bool canJump(vector<int>& nums) {
		//O(n)
       int i = 0;

       //find the farthest you can reach right now and iterate closer
       for(int reach = 0; i < nums.size() && i <= reach; i++)
        {
            reach = max(i+ nums[i], reach);
        }
       return i == nums.size();
    }
};