//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        //if the vector is empty, return false
        int n = nums.size();
        if (n == 0) 
        {
            return false;
        }
        
        //setup the edges
        int high = n - 1;
        int low = 0;

        //while our edges are not equal
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if ( nums[low] != target ) {
                low++;
                continue;
            }

            //      which array does pivot belong to.
            bool pivotArrayisHigh = (nums[low] <= nums[mid]);

            //      which array does target belong to.
            bool targetArrayisHigh = (nums[low] <= target);
            
            //shift to the target array 
            if (pivotArrayisHigh ^ targetArrayisHigh) 
            {   //If pivot and target exist in different sorted arrays
                
                //shift to the subarray with the targetArray
                if (pivotArrayisHigh) 
                {
                    low = mid + 1; //         pivot in the first, target in the second
                } 
                else 
                {
                    high = mid - 1; //       target in the first, pivot in the second
                }
            } 
            else 
            { //         If pivot and target exist in same sorted array
                if (nums[mid] < target) 
                {
                    //shift to the right of the subarray
                    low = mid + 1;
                } 
                else 
                {
                    //shift to the left of the subarray
                    high = mid - 1;
                }
            }
        }
        return false;
    }

    
};