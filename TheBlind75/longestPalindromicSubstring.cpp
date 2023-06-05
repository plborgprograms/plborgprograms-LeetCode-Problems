// https://leetcode.com/problems/longest-palindromic-substring/submissions/
class Solution {
public:
    string longestPalindrome(string s) {
        //O(N^2)
        //This expands the search as you go to find the longest result
        //full comparison is unnecessary because individual chars are
        //much faster to compare

        string longestResult = "";
        for(int a = 0; a < s.length(); a++)
        {
            int m = a; int n = a;
            while(m > 0 && n < s.length()-1 && s[m-1] == s[n+1] )
            {
                m--; n++;
            }

            if(1+n-m > longestResult.length())
            {
                longestResult = s.substr(m,1+n-m);
            }
            m = a; n = a+1;
            if(s[m] == s[n])
            {
                while(m > 0 && n < s.length()-1 && s[m-1] == s[n+1] )
                {
                    m--; n++;
                }
                if(1+n-m > longestResult.length())
                {
                    longestResult = s.substr(m,1+n-m);
                }
            }
        }

        return longestResult;
    }
};