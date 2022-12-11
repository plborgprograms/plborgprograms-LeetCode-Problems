//https://leetcode.com/problems/contiguous-array/submissions/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        //keep a running map of the first time each balance is found
        unordered_map<int,int> mp; mp[0]=-1;

        int currentBalance = 0,longest_subarray = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            currentBalance += nums[i] == 0 ? - 1 : 1;    
            if(mp.find(currentBalance) != mp.end())
            {
                //this makes the assumption that any other time there was this balance would be a valid result
                if(longest_subarray < i - mp[currentBalance])
                {
                    //if the longest found subarray is less than the current
                    //subarray, set this as equal
                    longest_subarray = i - mp[currentBalance];
                }
            }
            else
            {
                mp[currentBalance] = i;
            }
        }
        return longest_subarray;
    }
};