//https://leetcode.com/problems/binary-search/submissions/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //O(log2n)
        int low = 0;
        int mid = floor(nums.size()/2);
        int high = nums.size()-1;


        do
        {
            if(nums[mid] == target)
            {
                return mid;
                break;
            }
            else if(target < nums[mid])
            {
                high = mid-1;
                mid = (low+high)/2;
            }
            else //target > nums[mid]
            {
                low = mid+1;
                mid = (low+high)/2;
            }
        }while(low <= high);

        return -1;
    }
};