//https://leetcode.com/problems/palindromic-substrings/submissions/
class Solution {
public:
    int countSubstrings(string s) {
        //O(N^2)
        //This expands the search as you go to find the longest result
        //full comparison is unnecessary because individual chars are
        //much faster to compare
        int totalPalindromes = 0;

        for(int a = 0; a < s.length(); a++)
        {
            int m = a; int n = a;
            totalPalindromes++;
            while(m > 0 && n < s.length()-1 && s[m-1] == s[n+1] )
            {
                totalPalindromes++;
                m--; n++;
            }

            m = a; n = a+1;
            if(s[m] == s[n])
            {
                totalPalindromes++;
                while(m > 0 && n < s.length()-1 && s[m-1] == s[n+1] )
                {
                    totalPalindromes++;
                    m--; n++;
                }
                
            }
        }

        return totalPalindromes;
    }
};