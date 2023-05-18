//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //O(n) where n is s.length()

        //iterate over the string adding each letter to a hashmap of counts of that letter
        //use the int of the entry to determine if that int has already been found.

        if(s.length() < 2)
        {
            return s.length();
        }

        unordered_map<char, int> charCounts;
        int startOfSeries = 0;

        int longestSequence = 1; //assumes size of 2 or more
        for(int endOfSeries = 0; endOfSeries < s.length(); endOfSeries++)
        {
            charCounts[ s[endOfSeries] ]++;

            if(charCounts[ s[endOfSeries] ] > 1)
            {
                longestSequence = max(longestSequence, endOfSeries - startOfSeries);

                while(charCounts[ s[endOfSeries] ] > 1 && startOfSeries < endOfSeries)
                {
                    charCounts[ s[startOfSeries] ]--; //or pop_front
                    startOfSeries++;
                }
            }
        }
        longestSequence = max(longestSequence, (int)s.length() - startOfSeries);

        return longestSequence;
    }
};