class Solution {
//https://leetcode.com/problems/unique-paths-ii/submissions/
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //iterate over the grid starting from the bottom right.
        //get the sum of the two totals down and right of it.
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> pathsFromHere(m,vector<long>(n,0));
        
        if(obstacleGrid[ obstacleGrid.size()-1][ obstacleGrid[0].size()-1] == 1)
        {
            return 0;
        }
        
        
        for(int row = obstacleGrid.size()-1; row >= 0; row--)
        {
            for(int col = obstacleGrid[0].size()-1; col >= 0; col--)
            {
                if(obstacleGrid[row][col]) //blocked
                {
                    pathsFromHere[row][col] = 0;
                }
                else if( row == obstacleGrid.size()-1 && col == obstacleGrid[0].size()-1)
                {
                    pathsFromHere[row][col] = 1;
                }
                else
                {
                    int total = 0;
                    if(col < obstacleGrid[0].size()-1 ) //right
                    {
                        total += pathsFromHere[row][col+1];
                    }
                    if(row < obstacleGrid.size()-1 ) //down
                    {
                        total += pathsFromHere[row+1][col];
                    }
                    pathsFromHere[row][col] = total;
                }
                
            }
        }
        
        
        return pathsFromHere[0][0];
    }
};