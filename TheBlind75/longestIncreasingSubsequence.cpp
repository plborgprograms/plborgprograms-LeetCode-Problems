//https://leetcode.com/problems/longest-increasing-subsequence/submissions/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //O(n^2)
        if(nums.size() == 0)
        {
            return 0;
        }
        int* dp = new int[nums.size()];
        int highestFound = 1;
        //initialize all nums as 0;
        
        //iterate starting from the second to last end 
        //Find if it's longer to include or exclude this number
        //keep a running max to the right and return the max

        dp[nums.size()-1] = 1;
        for(int n = nums.size()-2; n >= 0; n--)
        {
            dp[n] = 1;
            for(int i = n+1; i < nums.size(); i++)
            {
                if(nums[n] < nums[i])
                {
                    dp[n] = max(dp[n], dp[i]+1);
                }
            }
            highestFound = max(dp[n], highestFound);
        }

        return highestFound;
    }
};