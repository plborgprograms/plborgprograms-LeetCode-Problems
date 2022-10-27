//https://leetcode.com/problems/subsets/submissions/
class Solution {
public:
    
    vector<vector<int>> results;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //iterate over the list continuing with the current entry and without the current entry
        //when the program has gotten to the end of the list, add the result to results.
        vector<int> starterSet;
        subset(nums, 0, starterSet);
        return results;
    }
    
    void subset(vector<int> nums, int iterator, vector<int> currentSet)
    {
        if(iterator == nums.size())
        {
            results.emplace_back(currentSet);
        }
        
        if(iterator < nums.size() )
        {
            subset(nums, iterator+1, currentSet);
            currentSet.emplace_back(nums[iterator]);
            subset(nums, iterator+1, currentSet);
        }
    }
    
};