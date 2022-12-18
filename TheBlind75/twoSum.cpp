//https://leetcode.com/problems/two-sum/submissions/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		//O(n)
		//iterate over the vector and if you find a total that adds to target, return the combination
		
        //number, index
        unordered_map<int, int> previousEntries;

        for(int i = 0; i < nums.size(); i++)
        {
            if(previousEntries.find(target-nums[i]) != previousEntries.end())
            {
                vector<int> result;
                result.emplace_back(i);
                result.emplace_back(previousEntries[target-nums[i]]);
                return result;
            }
            previousEntries[nums[i]] = i;
        }
        vector<int> result;
        return result;
    }
};