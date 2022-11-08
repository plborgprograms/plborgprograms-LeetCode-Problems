//https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        vector<vector<char>> grid(3, vector<char>(3, ' '));
        int m = 0;
        for(m = 0; m < moves.size(); m++)
        {
            int col = moves[m][0];
            int row = moves[m][1];

            char playerChar = m % 2 == 0 ? 'X' : 'O';
            grid[row][col] = playerChar;
            if(checkFinished(grid, playerChar))
            {
                //printGrid(grid);
                return m % 2 == 0 ? "A" : "B";
            }
        }

        return m == 9 ? "Draw" : "Pending";
    }

    void printGrid(vector<vector<char>> grid)
    {
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                cout << grid[row][col] << ",";
            }

            cout << endl;
        }
        cout << endl;
    }

    bool checkFinished(vector<vector<char>> grid, char playerChar)
    {
        for(int i = 0; i < grid.size(); i++)
        {
            if((grid[i][0] == playerChar && grid[i][1]== playerChar && grid[i][2]== playerChar) ||
                (grid[0][i] == playerChar && grid[1][i] == playerChar && grid[2][i] == playerChar))
            {
                return true;
            }
        }

        if(  (grid[0][0] == playerChar && grid[1][1] == playerChar && grid[2][2] == playerChar) ||
                (grid[2][0] == playerChar && grid[1][1] == playerChar && grid[0][2] == playerChar ) )
        {
            return true;
        }

        return false;
    }
};