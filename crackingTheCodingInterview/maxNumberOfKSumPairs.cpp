//https://leetcode.com/problems/max-number-of-k-sum-pairs/submissions/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int, int> numberCount;
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(numberCount[nums[i]])
            {
                
                numberCount[nums[i]]++;
            }
            else
            {
                numberCount[nums[i]]=1;
            }

            if( (k-nums[i]!=nums[i] && numberCount[k-nums[i]] > 0) || 
            (k-nums[i]==nums[i] && numberCount[nums[i]]>=2))
            {
                numberCount[k-nums[i]]--;
                numberCount[nums[i]]--;
                result++;
            }
        }
        return result;
    }
};