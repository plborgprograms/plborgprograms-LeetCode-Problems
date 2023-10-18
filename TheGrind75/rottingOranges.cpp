//https://leetcode.com/problems/rotting-oranges/submissions/
class Solution {
public:

    vector<vector<int>> oranges;
    vector<vector<bool>> enqueued;

    queue<pair<int,int>> visitQueue;

    int totalToRot = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        //O(N)
        oranges = grid;
        enqueued = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        //find 0s first. make a list of them and then for each one visit all adjacent
        //cells, doing a breadth first search. Never visit a cell more than once.
        for(int row = 0; row < oranges[0].size(); row++)
        {
            for(int col = 0; col < oranges.size(); col++)
            {
                if(oranges[col][row] == 2)
                {
                    //result[col][row] = 0;
                    visitQueue.push(pair(col,row));
                    enqueued[col][row] = true;
                }
                else if(oranges[col][row] == 1)
                {
                    totalToRot++;
                }
            }
        }

        int result = 0;
        pair endOfDayStop = pair(-1,-1);
        visitQueue.push(endOfDayStop);
        while(!visitQueue.empty())
        {
            pair current = visitQueue.front();
            visitQueue.pop();
            if(current == endOfDayStop && !visitQueue.empty())
            {
                visitQueue.push(endOfDayStop);
                result++;
            }
            {
                explore(current.first, current.second);
            }
        }

        if(totalToRot > 0)
        {
            return -1;
        }

        return result;
    }

    void explore(int col, int row)
    {
        //int here = result[col][row];
        int here = 0;

        Check(col,row-1);
        Check(col-1,row);
        Check(col+1,row);
        Check(col,row+1);

        //if using diagonal, uncomment
        //Check(col-1,row-1);
        //Check(col-1,row+1);
        //Check(col+1,row-1);
        //Check(col+1,row+1);
    }

    void Check(int col, int row)
    {
        if(okay(col, row))
        {
            visitQueue.push(pair(col,row));
            enqueued[col][row] = true;
            totalToRot--;
        }
    }

    bool okay(int col, int row)
    {
        return col >= 0 && col < oranges.size() && row >= 0 && row < oranges[0].size() && !enqueued[col][row] && oranges[col][row] == 1;
    }

};