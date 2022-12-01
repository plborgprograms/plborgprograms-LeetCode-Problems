//https://leetcode.com/problems/house-robber/submissions/
class Solution {
public:
    int rob(vector<int>& nums) {
        //O(N)
        int oneBack = 0;
        int twoBack = 0;

        //iterate over all entries and find if it's
        //higher with the current or the previous 
        //answer
        for (int i = 0; i < nums.size(); i++) 
        {
            int tmp = oneBack;
            oneBack = max(twoBack + nums[i], oneBack);
            twoBack = tmp;
        }

        //oneBack is always the highest, so return it
        return oneBack;
    }

    

};