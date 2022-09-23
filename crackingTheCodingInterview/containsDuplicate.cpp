//https://leetcode.com/problems/valid-anagram/submissions/
class Solution {
public:
    typedef unordered_map<char, int> letterCounts;
    bool isAnagram(string s, string t) {
        
        return ( totals(s) == totals(t) );
    }
    
    letterCounts totals(string input)
    {
        letterCounts result;
        for(int x = 0; x < input.size(); x++)
        {
            if(result.find(input[x]) != result.end())
            {
                result[ input[x] ]++;
            }
            else
            {
                result[ input[x] ] = 1;
            }
        }
        
        return result;
    }
};