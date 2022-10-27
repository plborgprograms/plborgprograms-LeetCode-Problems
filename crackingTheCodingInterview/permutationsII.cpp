//https://leetcode.com/problems/permutations-ii/submissions/
class Solution {
public:
    //adapted from https://leetcode.com/problems/permutations/
    //sorting and checking for equality before swaps, allows for duplicates
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //iterate over the list lockin in each element of the sublist almost like a bubble sort
        sort(nums.begin(), nums.end());
        Reorder(nums, 0);
        return results;
    }
    
    vector<vector<int>> results;
    
    void Reorder(vector<int> currentSet, int startingWith)
    {
        if(startingWith == currentSet.size()-1)
        {
            results.emplace_back(currentSet);
            return;
        }
        
        Reorder(currentSet, startingWith+1);
        for(int x = startingWith+1; x < currentSet.size(); x++)
        {
            if(currentSet[startingWith] != currentSet[x])
            {
                int temp = currentSet[x];
                currentSet[x] = currentSet[startingWith];
                currentSet[startingWith] = temp;
                Reorder(currentSet, startingWith+1);
            }
        }
    }
    
};