// https://leetcode.com/problems/contains-duplicate/submissions/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> previousEntries;
        for(int x = 0; x < nums.size(); x++)
        {
            if(previousEntries.find(nums[x]) != previousEntries.end() )
            {
                return true;
            }
            previousEntries[nums[x]] = nums[x];
        }
        
        return false;
    }
};