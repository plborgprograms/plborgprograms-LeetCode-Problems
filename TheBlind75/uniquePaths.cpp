//https://leetcode.com/problems/unique-paths/submissions/
class Solution {
public:
    int uniquePaths(int m, int n) {
		//O(m*n)
        //declare array
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //iterate over loop
        for(int row = n-1; row >= 0; row--)
        {
            for(int col = m-1; col >= 0; col--)
            { //setting each value to dp[x+1]+val[y+1]
                int temp = (col < m-1) ? dp[col+1][row] : 0;
                temp += (row < n-1) ? dp[col][row+1] : 0;
                temp = (row == n-1 && col == m-1) ? 1 : temp;
                dp[col][row] = temp;
            }
        }
       

        return dp[0][0];
    }
};