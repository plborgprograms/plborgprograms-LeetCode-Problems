//https://leetcode.com/problems/maximum-product-subarray/submissions/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //O(n)
        //dual iterators solution

		//This updates running totals in case of negatives
		//and resets the product to 1 if a number is a zero.
		//The max needs to be calculated first because the 
		//subtotal being reset to 1.
        int leftSubtotal = 1;
        int rightSubtotal = 1;
        int maxResult = std::numeric_limits<int>::lowest();
        for(int i = 0; i < nums.size(); i++)
        {
            //max needs to be calculated first in case of 0
            maxResult = max(maxResult, max(leftSubtotal * nums[i], rightSubtotal * nums[nums.size() -1 - i]) );

            //update other running totals depending on if it's a zero
            leftSubtotal = nums[i] ? leftSubtotal * nums[i] : 1;
            rightSubtotal = nums[nums.size()-1-i] ? rightSubtotal * nums[nums.size() -1 - i] : 1;   
        }

        return maxResult;
    }
};