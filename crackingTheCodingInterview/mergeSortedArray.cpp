//https://leetcode.com/problems/merge-sorted-array/submissions/
class Solution {
public:
    void merge(vector<int>& nums1, int nums1Length, vector<int>& nums2, int nums2Length) {
        //iterate over both and while nums2's front is less than the 
        //current cell in nums1, insert it
        
        for(int i = 0; i < nums1Length && nums2.size() > 0; i++)
        {
            if(nums2[0] < nums1[i])
            {
                nums1.insert(nums1.begin() + i, nums2[0]);
                nums1Length++;
                nums1.pop_back();
                nums2.erase(nums2.begin());
            }
        }
        
        //catch any lingering nums2 instances
        while(nums2.size() > 0)
        {
            nums1[nums1Length] = nums2[0];
            nums2.erase(nums2.begin());
            nums1Length++;
        }
        
    }
};