// https://leetcode.com/problems/house-robber-ii/submissions/
class Solution {
public:
int rob(vector<int>& nums) {
		//O(n)
        if(nums.size() == 0)
        {
            return 0;
        }
        else if(nums.size() == 1)
        {
            return nums[0];
        }
		
		//compare the two results with one including the first and excluding the last
		//and the other excluding the first and including the last, for the wraparound case
        return max(HighestOfSubset( nums, 0,nums.size()-1), HighestOfSubset( nums, 1,nums.size()));
    }

    int HighestOfSubset(vector<int> nums, int startpoint, int endpoint)
    {
        int prev1 = 0, prev2 = 0;

        //iterate over the whole list updating
        //the prev 2 spaces back since you can't
		//have 2 adjacent 
        for(int h = startpoint; h < endpoint; h++)
        {
            
            int includingCurrent = prev2 + nums[h];
            int excludingCurrent = max(prev1,prev2);

            prev1 = includingCurrent;
            prev2 = excludingCurrent;
        }
        return max(prev1,prev2);
    }
    
};