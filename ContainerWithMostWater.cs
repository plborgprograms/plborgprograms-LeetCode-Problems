using System;

//from https://leetcode.com/problems/container-with-most-water/
public class Solution {
    
    public int MaxArea(int[] height) {
        int bestResult = -1;
        
        int l = 0; 
        int r = height.Length-1;
        
        //start from the edges and step one closer to each other each loop until you have the best results
        
        //this way, the width between the two points will automatically be reduced
        //by one each loop and it'll ensure the higher one is preserved
        while(l < r)
        {
            int currentComparison = CalculateArea(height[l], l, height[r], r);
            if(currentComparison > bestResult)
            {
                bestResult = currentComparison;
            }
            
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        
        return bestResult;
    }
    
    public int CalculateArea(int leftHeight, int leftIndex, int rightHeight, int rightIndex)
    {
        /*int height = Math.Max(leftHeight, rightHeight);
        int width = rightIndex - leftIndex;
        return (height*width);*/
        
        return (Math.Min(leftHeight, rightHeight)) * (rightIndex - leftIndex);
    }
}