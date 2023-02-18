//https://leetcode.com/problems/longest-common-subsequence/submissions/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {        
        //O(m*n)
        //iterate over the two strings and find 
        //intersections of the two words
        //only move diagonally to prevent cases
        //in which a letter matches to multiple counterparts
        //add 1 column and row, to remove if checks on the
        //far left column and top row.

        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1));
        for(int t1 = 0; t1 < text1.length(); t1++)
        {
            for(int t2 = 0; t2 < text2.length(); t2++)
            {
                dp[t1 + 1][t2 + 1] = text1[t1] == text2[t2] ? dp[t1][t2] + 1 : max(dp[t1 + 1][t2], dp[t1][t2 + 1]);
            }
        }
        int longestSubsequence = dp[text1.length()][text2.length()];
        return longestSubsequence;
    }
};