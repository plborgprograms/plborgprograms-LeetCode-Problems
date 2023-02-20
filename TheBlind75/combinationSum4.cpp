//https://leetcode.com/problems/combination-sum-iv/submissions/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //O(m*n) where m = target
        vector<int> dp(target+1,0);
        //run through the whole list of totals between
        //0 and target. Handle the edge case of the
        //number of totals being greater than the maximum
        //of int.
        for(int t = 0; t <= target; t++)
        {
            for(int n = 0; n < nums.size(); n++)
            {
                if(t + nums[n] <= target)
                {
                    if(t == 0)
                    {
                        dp[nums[n]] = 1;
                    }
                    else if(dp[t])
                    {
                        if((long)dp[t+nums[n]]+dp[t] < INT_MAX)
                        {
                            dp[t+nums[n]] += dp[t];
                        }
                        else
                        {
                            dp[t+nums[n]] = INT_MAX;
                        }
                    }
                }
            }
        }


        return dp[target];
    }
};