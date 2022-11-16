//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {    
        //find the front and back of the unsorted section
        //return the total length
        vector<int> sorted(nums);
        sort(nums.begin(), nums.end());

        int l = 0;
        while (l < nums.size() && nums[l] == sorted[l] )
        {
            l++;
        }
        if(l == nums.size())
        {
            return 0;
        }

        int r = nums.size()-1;
        while (nums[r] == sorted[r] && r > l)
        {
            r--;
        }

        return (r - l)+1;
    }
};