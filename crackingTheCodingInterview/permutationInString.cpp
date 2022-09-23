//https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    typedef unordered_map<char, int> letterCounts;

    bool checkInclusion(string s1, string s2) {
        letterCounts smaller = totals(s1);
        letterCounts larger = totals(s2);
        
        
        for(letterCounts::iterator it = smaller.begin(); it != smaller.end(); ++it)
        {
            if(larger.find(it->first) != larger.end() && larger[it->first] >= smaller[it->first] )
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        
        return true;
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