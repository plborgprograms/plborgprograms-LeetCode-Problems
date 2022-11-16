//https://leetcode.com/problems/maximum-subarray/submissions/
class Solution {
public:
    int maxSubArray(vector<int>& input) {
        //iterate over all numbers and ensure
        //that the set is always growing by
        //resetting it to 0 if it is less than 0.
        int runningTotal = 0;
        double result = -1.0/0.0;
        for (int num : input) 
        {
            runningTotal += num;
            result = (result > runningTotal) ? result : runningTotal;
            if (runningTotal < 0) 
            {
                //restart the result as if the result set were empty
                runningTotal = 0;
            }
        }
        return result;
    }
};