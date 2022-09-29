//https://leetcode.com/problems/rotate-image/submissions/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //rotate the four characters using a swap
        int width = matrix.size();
        
        
        //in odd number cases, I want the middle case to only be rotated once which is why one is a ceil and the other is a floor
        for(int row = 0; row < (matrix.size()/2); row++)
        {
            for(int col = 0; col < ceil((double)matrix.size()/2); col++)
            {
                //offset each by the row and column variables which need to be swapped for each of the four corners
                int temp = matrix[row ][col];
                matrix[row ][col] = matrix[width-1-col][row];
                matrix[width-1-col][row] = matrix[width-1-row][width-1-col];
                matrix[width-1-row][width-1-col] = matrix[col][width-1-row];
                matrix[col][width-1-row] = temp;
                
            }
        }
        
        //just for testing
        /*for(int row = 0; row < matrix.size(); row++)
        {
            for(int col = 0; col < matrix.size(); col++)
            {
                cout <<  matrix[row][ col] << ",";
            }
            cout << endl;
        }*/
    }
};