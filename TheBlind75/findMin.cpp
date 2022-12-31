//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
		//O(N*log(N) )
        //do a binary search and narrow in on the inconsistency
        int high = nums.size()-1;
        int low = 0;

        if(nums[low] < nums[high])
        {
            return nums[0];
        }

        while(high-low > 1)
        {
            int mid = (high + low)/2;
            if(!(nums[low] < nums[mid]))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }

        return nums[high];
    }
};