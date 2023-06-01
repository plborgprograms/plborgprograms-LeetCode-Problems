//https://leetcode.com/problems/valid-palindrome/submissions/
class Solution {
public:
    bool isPalindrome(string s) {
        //O(n)
        //convert chars to lower and filter them

        //convert to lower and remove chars
        int difference = 'A'-'a';
        for(int i = 0; i < s.length(); i++)
        {
            if( (s[i] <= 'z' && s[i] >= 'a') ||
            (s[i] <= '9' && s[i] >= '0') )
            {
                continue;
            }
            else if(s[i] <= 'Z' && s[i] >= 'A')
            {
                s[i] -= difference;
            }
            else
            {
                s.erase(i,1);
                i--;
            }
        }

        //compare the resulting strings
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        return (s == reversed);

        //this could be faster
        /*for(int i = 0; i < s.length()/2; i++)
        {
            if(s[i] != s[s.length()-1-i])
            {
                return false;
            }
        }

        return true;
        */

        //alternatively, a dual iterator approach may be faster
    }
};