//https://leetcode.com/problems/01-matrix/submissions/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<bool>> enqueued;

    queue<pair<int,int>> visitQueue;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //O(N)
        result = mat;
        enqueued = vector<vector<bool>>(mat.size(), vector<bool>(mat[0].size(), false));

        //find 0s first. make a list of them and then for each one visit all adjacent
        //cells, doing a breadth first search. Never visit a cell more than once.
        for(int row = 0; row < mat[0].size(); row++)
        {
            for(int col = 0; col < mat.size(); col++)
            {
                if(mat[col][row] == 0)
                {
                    result[col][row] = 0;
                    visitQueue.push(pair(col,row));
                    enqueued[col][row] = true;
                }
            }
        }

        while(!visitQueue.empty())
        {
            pair current = visitQueue.front();
            visitQueue.pop();
            explore(current.first, current.second);
        }


        return result;
    }

    void explore(int col, int row)
    {
        int here = result[col][row];

        Check(col,row-1, here);
        Check(col-1,row, here);
        Check(col+1,row, here);
        Check(col,row+1, here);

        //if using diagonal, uncomment
        //Check(col-1,row-1, here);
        //Check(col-1,row+1, here);
        //Check(col+1,row-1, here);
        //Check(col+1,row+1, here);
    }

    void Check(int col, int row, int prev)
    {
        if(okay(col, row))
        {
            result[col][row] = prev+1;
            visitQueue.push(pair(col,row));
            enqueued[col][row] = true;
        }
    }

    bool okay(int col, int row)
    {
        return col >= 0 && col < result.size() && row >= 0 && row < result[0].size() && !enqueued[col][row];
    }
};