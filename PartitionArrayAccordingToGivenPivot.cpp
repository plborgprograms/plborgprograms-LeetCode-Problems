//https://leetcode.com/problems/partition-array-according-to-given-pivot/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int> lessThan;
        vector<int> equal;
        vector<int> greaterThan;
           
        for(int x = 0; x < nums.size(); x++)
        {
            if(nums[x] < pivot)
            {
                lessThan.push_back(nums[x]);
            }
            if(nums[x] == pivot)
            {
                equal.push_back(nums[x]);
            }
            if(nums[x] > pivot)
            {
                greaterThan.push_back(nums[x]);
            }
        }
        
        
        vector<int> result;
        result.insert( result.end(), lessThan.begin(), lessThan.end() );
        result.insert( result.end(), equal.begin(), equal.end() );
        result.insert( result.end(), greaterThan.begin(), greaterThan.end() );
        
        return result;
    }
};