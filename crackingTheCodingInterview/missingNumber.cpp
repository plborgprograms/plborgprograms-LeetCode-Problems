//https://leetcode.com/problems/missing-number/description/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int missing = 0;

        //build a cumulation of every number in the array (nums)
        //and every number that should be in a complete array Sum(i)
        //the difference of the two will show the missing number
        for (int i = 0; i < nums.size(); i++)
        {
            missing += i+1 - nums[i];
        }

        return missing;
        

        //alternatively
        //the more easy to understand version (but uses an extra variable and extra calculations)
        /*
        int shouldBeThereSum = 0, sumOfArray = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            shouldBeThereSum += i+1;
            sumOfArray += nums[i];
        }

        //the difference of everything that should be there and what is there will result in the missing number
        return shouldBeThereSum - sumOfArray;
        */
    }
};