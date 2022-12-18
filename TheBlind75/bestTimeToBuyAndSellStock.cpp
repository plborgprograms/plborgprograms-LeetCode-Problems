//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //O(n)

        //iterate over list and find the lowest at that point
        //anc check if the difference is greater than any
        //recorded before.
        int lowest = prices[0];
        int bestDifference = 0;

        for(int s = 0; s < prices.size(); s++)
        {
            if(prices[s] < lowest)
            {
                lowest = prices[s];
            }

            if(prices[s] - lowest > bestDifference)
            {
                bestDifference = prices[s] - lowest;
            }
        }

        return bestDifference;
    }
};