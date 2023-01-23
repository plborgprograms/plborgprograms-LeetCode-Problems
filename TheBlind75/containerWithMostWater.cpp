//https://leetcode.com/problems/container-with-most-water/submissions/
class Solution {
public:
    int maxArea(vector<int>& height) {
        //O(n)
		
        //iterate over the vector with two iterators
        //move the lower of the two. calculate the height
        //based on the difference between the two

        int greatest = 0;

        int l = 0; int r = height.size()-1;
        while(l < r)
        {
            long current = min(height[l], height[r]) * (r-l);
            if(current > greatest)
            {
                greatest = current;
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

        return greatest;
    }
};