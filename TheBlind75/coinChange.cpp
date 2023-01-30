//https://leetcode.com/problems/coin-change/submissions/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		//O(m*n) where m = coins.size(), n = amount

        //set up a two dimensional array
        //x axis the coins
        //y axis every amount between 0 and the target
        int dp[amount+1];
        sort(coins.begin(), coins.end());

        dp[0] = 0;
        for(int a = 1; a < amount+1; a++)
        {
            dp[a] = amount+1;
            for(int c = 0; c < coins.size(); c++)
            {
                if(coins[c] <= a)
                {
                    //try getting the best result by adding the current coin
                    //value to the last running total that would bring the total
                    //to this amount.
                    dp[a] = min(dp[a], dp[a-coins[c]]+1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};