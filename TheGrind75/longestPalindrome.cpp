//https://leetcode.com/problems/longest-palindrome/submissions/
class Solution {
public:
    int longestPalindrome(string s) {
        //O(n)
        //iterate over letters getting totals of each letter.
        //Pairs can all be used plus one item standalone
        //at the middle so keep track of the OddTotals
        //and pair off all the others.

        unordered_map<char, long> letterCounts;

         int total = 0;

        int countOfOddTotals = 0;
        for(int a = 0; a < s.length(); a++)
        {
            if( letterCounts.find(s[a]) == letterCounts.end())
            {
                letterCounts[s[a]] = 0;
            }
            
            letterCounts[s[a]]++;
            if(letterCounts[s[a]]%2 == 0)
            {
                total+=2;
                countOfOddTotals--;
            }
            else
            {
                countOfOddTotals++;
            }
        }

        //iterate over letter counts totalling them
       
       total += (countOfOddTotals > 0);
        


        return total;
    }
};