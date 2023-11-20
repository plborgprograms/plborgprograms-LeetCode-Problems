//https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        //O(N)
        //iterate over the vector and cache the first value less than
        //the current height (everything in between is the same or higher).
        //Use the cache to shorten all future values. If the item just to 
        //the left is the same or higher, the furthest point of equal value
        //will be the same. If the item just to the left is lower than the
        //current index, stop there immediately. Do this for the items
        //to the right as well. 

        //use the calculated values to quickly calculate the largest rectangle
        //that uses the current index's height.
        if(heights.empty())
        {
            return 0;
        }
        int n = heights.size();

        //initializing all values as 0 and reassigning one value is quicker than
        //assigning the whole vector to the default value of -1 and n.
        vector<int> firstLeftValueLessThan(n,0);
        vector<int> firstRightValueLessThan(n,0);

        //iterate over the vector and cache the first value less than
        //the current height (everything in between is the same or higher).
        //Use the cache to shorten all future values. If the item just to 
        //the left is the same or higher, the furthest point of equal value
        //will be the same. If the item just to the left is lower than the
        //current index, stop there immediately. 
        firstLeftValueLessThan[0] = -1;
        for(int i = 1; i < n; i++)
        {
            int l = i-1;
            while(l >= 0 && heights[l] >= heights[i])
            {
                l = firstLeftValueLessThan[l];
            }
            firstLeftValueLessThan[i] = l;
        }


        //Do the same starting from the right side
        //iterate over the vector and cache the first value less than
        //the current height (everything in between is the same or higher).
        //Use the cache to shorten all future values. If the item just to 
        //the right is the same or higher, the furthest point of equal value
        //will be the same. If the item just to the right is lower than the
        //current index, stop there immediately. 

        //Start the initial value just outside of range
        firstRightValueLessThan[n-1] = n;

        for(int i = n-2; i >= 0; i--)
        {
            int r = i+1;
            while(r < n && heights[r] >= heights[i])
            {
                r = firstRightValueLessThan[r];
            }
            firstRightValueLessThan[i] = r;
        }

        //use the calculated values to quickly calculate the largest rectangle
        //that uses the current index's height.
        int largestRectangle = 0;
        for(int i = 0; i < n; i++)
        {
            largestRectangle = max(largestRectangle, heights[i]*(firstRightValueLessThan[i]-firstLeftValueLessThan[i]-1));
        }

        return largestRectangle;
    }
};