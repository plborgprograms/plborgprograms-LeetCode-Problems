//https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        //O(total*N)
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if(sum%2 != 0)
        {
            return false;
        }


        int target = sum/2;

        //run a dynamic programming 2d vector of all the totals that will equal half the total
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1));
        for(int i = 0; i < dp[0].size(); i++)
        {
            dp[0][i]=false;
        }
        for(int i = 0; i < dp.size(); i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<dp.size();i++)
        {
            int item = nums[i-1];
            for(int j=1;j<dp[0].size();j++)
            {
                //current coordinate is true if the row directly to the left or the row 'item' rows above it is true;
                //in other words, can this be reached by adding numbers together; if the number 'item' rows before
                //could be added to, this one can as well.
                dp[i][j]= dp[i-1][j] || (item <= j && dp[i-1][j-item]);
            }
        }

        //if there's a side that equals the target which is half the total, there must be another side that equals the other half
        //therefore proving the equal sides
        return dp[nums.size()][target];
    }
};