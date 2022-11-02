//https://leetcode.com/problems/coin-change-ii/submissions/
class Solution {
public:

    int change(int targetAmount, vector<int>& coins) 
    {
        //iterate over each number until you get past the target number
        
        //initialize with a massive number
        int uniquePermutationsThatAddTo[5001] = { 1 };
        
        //get the count of permutations that add to each number between 0 and amount
        for (auto currentCoin : coins)
        {
            for (auto currentTotal = currentCoin; currentTotal <= targetAmount; currentTotal++)
            {
                uniquePermutationsThatAddTo[currentTotal] += uniquePermutationsThatAddTo[currentTotal - currentCoin];
            }
        }
        /*for(int x = 0; x <= targetAmount; x++)
        {
            cout << uniquePermutationsThatAddTo[x] << ", ";
        }*/
        return uniquePermutationsThatAddTo[targetAmount];
    }
    
};