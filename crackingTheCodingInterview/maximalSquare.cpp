// https://leetcode.com/problems/maximal-square/submissions/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //O(m*n)
        //iterate over the matrix, adding to the min of
        //the totals found up or left of the current cell.

        if (matrix.empty()) {
            return 0;
        }
        int rows = matrix.size(), cols = matrix[0].size(), largestFound = 0, upAndLeftCell;
        vector<int> currentRow(cols, 0);
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                int aboveCell = currentRow[j];
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    currentRow[j] = matrix[i][j] - '0';
                } else {
                    currentRow[j] = min(upAndLeftCell, min(currentRow[j], currentRow[j - 1])) + 1;
                }
                largestFound = max(currentRow[j], largestFound);
                upAndLeftCell = aboveCell;
            }
        }
        return largestFound * largestFound;
    }
};