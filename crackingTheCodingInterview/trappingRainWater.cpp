//https://leetcode.com/problems/trapping-rain-water/submissions/
class Solution {
public:
    int trap(vector<int>& height) {
		//O(n)
        //run two iterators. One from the left and one from the right
        //Get the minimum of the two highs by comparing max is higher
        //and getting the low of the two. 

        int totalWater = 0;

        int left = 0; int right = height.size()-1;
        int leftMax = 0; int rightMax = 0;
        while(left <= right)
        {
            if(max(height[left], leftMax) <= max(height[right], rightMax) ) 
            {
                if(height[left] > leftMax)
                {
                    leftMax = height[left];
                }
                else 
                {
                    totalWater += (leftMax - height[left]);
                }
                left++;
            }
            else
            {
                if(height[right] > rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    totalWater += (rightMax - height[right]);
                }
                right--;
            }
        }

        return totalWater;
    }
};