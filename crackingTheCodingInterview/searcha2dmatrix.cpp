//https://leetcode.com/problems/search-a-2d-matrix-ii/discussion/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //search from the topright to bottom left. if the current
		//value is too high, go left. If it's too low, go to the 
		//next line.

        int row = 0;
        int col = matrix[0].size()-1;
        //for(int row = 0; row < matrix.size(); row++)
        while(row < matrix.size() && col >= 0)
        {
            int current = matrix [row][col];
            //cout << "checking:" << current << endl;
            if(current == target)
            {
                return true;
            }
            current > target ? col-- :row++ ;

        }

        return false;
    }
};