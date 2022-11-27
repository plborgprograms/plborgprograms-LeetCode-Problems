//https://leetcode.com/problems/majority-element/submissions/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		//O(1) + O(quicksort)
        sort(nums.begin(), nums.end());
        return nums[(nums.size()-1)/2];
    }
};