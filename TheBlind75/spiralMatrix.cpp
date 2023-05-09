//https://leetcode.com/problems/spiral-matrix/solutions/?orderBy=most_votes
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //O(n)
        
        //spiral until you hit an edge and then change direction
        //by changing velocities. Stop when the result is full

        vector<int> result(matrix.size() * matrix[0].size() );

        int matrixCounter = 0;

        //set your velocities that will update each time you hit a wall
        int xvelocity = 1; int yvelocity = 0;
        int currentx = 0; int currenty = 0;

        int northEdge = 1; int southEdge = matrix.size()-1;
        int westEdge = 0; int eastEdge = matrix[0].size()-1;

        result[matrixCounter] = matrix[currenty][currentx];
        matrixCounter++;

        while( matrixCounter < result.size() )
        {
            if(xvelocity > 0 && currentx >= eastEdge)
            {
                eastEdge--;
                xvelocity = 0; yvelocity = 1;
            }
            else if(xvelocity < 0 && currentx <= westEdge)
            {
                westEdge++;
                xvelocity = 0; yvelocity = -1;
            }
            else if(yvelocity > 0 && currenty >= southEdge)
            {
                southEdge--;
                xvelocity = -1; yvelocity = 0;
            }
            else if(yvelocity < 0 && currenty <= northEdge)
            {
                northEdge++;
                xvelocity = 1; yvelocity = 0;
            }

            currentx += xvelocity; currenty += yvelocity;

            result[matrixCounter] = matrix[currenty][currentx];
            matrixCounter++;

            
        }


        return result;
    }
};