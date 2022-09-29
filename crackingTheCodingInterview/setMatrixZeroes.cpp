//https://leetcode.com/problems/set-matrix-zeroes/submissions/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> cols;
        unordered_map<int, bool> rows;
        
        for(int r = 0; r < matrix[0].size(); r++)
        {
            for(int c = 0; c <matrix.size(); c++)
            {
                if(matrix[c][r] == 0)
                {
                    cols[c] = true;
                    rows[r] = true;
                }
            }
        }
        
        for(int r = 0; r < matrix[0].size(); r++)
        {
            for(int c = 0; c <matrix.size(); c++)
            {
                if(cols[c] == true || rows[r] == true)
                {
                    matrix[c][r] = 0;
                }
            }
        }
        
    }
};