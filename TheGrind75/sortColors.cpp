//
class Solution {
public:
    void sortColors(vector<int>& nums) {
		//O(N)
        int low = 0;
        int middle = 0;
        int high = nums.size()-1;
        while(middle <= high)
        {
            if(nums[middle] == 0)
            {   //middle is too low
                swap(nums[low], nums[middle]);
                low++;
                middle++;
            }
            else if(nums[middle] == 1)
            {
                //middle is in place
                middle++;
            }
            else //if(nums[middle] == 2)
            {
                //middle is too high
                swap(nums[middle], nums[high]);
                high--;
            }
        }
    }
};